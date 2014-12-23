#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "def.h"

int read_move(move_t);

int main(){
  printf("%i\n", F);
  read_move(NULL);
  return 0;
} 

//Reads a Capcom notation move
int read_move(move_t m){
  char dir;
  char atk[1024];
  int pos;

  char *line;
  line = NULL;

  size_t n = 1024;

  //Read a line and remove the delimeter
  n = getline(&(line), &n, stdin);
  line[n-1] = 0;

  //Split around the dot
  sscanf(line, "%c.%s\n", &dir, atk);

  //toupperstr(atk, n-1);

  printf("dir is %c\n", dir);
  printf("atk is %s\n", atk);

  return 0;
}
