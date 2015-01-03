#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "def.h"

int read_move(Move_t, char*);
Combo read_combo(void);

int main(){
  Combo c;
  while((c = read_combo())){
    print_combo(c);
    free_combo(c);
  }
  return 0;
} 

//Reads a Capcom notation move
int read_move(Move_t m, char *line){
  char *dir;
  char *atk;
  int pos;

  //Split around the dot
  dir = line;
  atk = index(line, '.');

  //TODO: If there is no dot, it is either only a direction
  //      or only an attack. Need to discern.

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

  c = NULL;

  part = strtok((line), ",");
  do{
    //Read in a move
    m = alloc_move();
    read_move(m, part);

    //Add it to the combo
    if(!c){
      c = init_combo(m);
      lst = c;
    } else {
      add_move_to_combo(m, lst);
      lst = lst->next;
    }
  } while((part = strtok(NULL, ",")));

  free(line);
  return c;
}


