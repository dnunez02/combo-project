#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "def.h"

int read_move(Move_t);

int main(){
  struct Move m;
  read_move(&m);

  print_move(&m);
  return 0;
} 

//Reads a Capcom notation move
int read_move(Move_t m){
  char *dir;
  char *atk;
  int pos;

  char *line;
  line = NULL;

  //Read a line and remove the delimeter
  size_t n;
  n = getline(&(line), &n, stdin);
  line[n-1] = 0;

  //Split around the dot
  dir = line;
  atk = index(line, '.');

  //TODO: If there is no dot, it is either only a direction
  //      or only an attack. Need to discern.

  //This assumes no dot means it must be an attack.
  if(!atk) {
    atk = line;
    dir = NULL;
  } else {
    atk[0] = 0;
    atk++;
  }

  m->direction = strtodir(dir);
  m->attack = strtoatk(atk);

  free(line);
  return 0;
}
