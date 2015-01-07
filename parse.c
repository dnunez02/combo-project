/*
 * Parsing Capcom notation moves
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "def.h"

//Reads a Capcom notation move
int read_move(Move_t m, char *line){
  char *dir;
  char *atk;
  char *temp;
  int pos;

  //Split around the dot
  dir = line;
  atk = index(line, '.');

  //This assumes no dot means it must be an attack.
  if(!atk) {
    int c;
    char *tmp = strdup(line);
    c = strtoatk(tmp);
    if(!c){
      m->direction = strtodir(line);
      m->attack = NONE;
    } else {
      m->direction = NONE;
      m->attack = c;
    }
    free(tmp);
  } else {
    atk[0] = 0;
    atk++;

    m->direction = strtodir(dir);
    m->attack = strtoatk(atk);
  }
  return 0;
}

//Reads a combo from stdin
Combo read_combo(void){
  char *line, *part;
  size_t n;

  line = NULL;

  n = getline(&(line), &n, stdin);
  
  if(n < 2 || n == -1) {
    if(line) free(line);
    return NULL;
  }
  
  line[n-1] = 0;

  //Head and tail of a combo
  Combo c, lst;
  Move_t m;
  char *note, *tmp, *debug_part;

  note = NULL;
  c = NULL;

  part = strtok((line), ",");
  do{

    //For use when printing errors
    debug_part = strdup(part);

    //Check for a note in parens next to a move
    if((note = index(part, '('))){
      note[0] = 0;
      tmp = note;

      //Remove leading spaces
      while(isspace(*(--tmp))) tmp[0] = 0;

      note++;
      
      if(!(tmp = rindex(note, ')'))){
	fprintf(stderr, "Mismatched parentheses in part: %s\n", debug_part);
	free(debug_part);
	free_combo(c);
	c = NULL;
	goto end;
      }
      
      tmp[0] = 0;

      //Remove trailing spaces
      while(isspace(*(++tmp))) tmp[0] = 0;
    }


    //Read in a move
    m = alloc_move();
    read_move(m, part);

    //Add it to the combo
    if(!c){
      c = init_combo(m, note);
      lst = c;
    } else {
      add_move_to_combo(m, note, lst);
      lst = lst->next;
    }

    free(debug_part);
  } while((part = strtok(NULL, ",")));

 end:
  free(line);
  return c;
}
