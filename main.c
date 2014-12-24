#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "def.h"

int read_move(move_t);
extern int strtodir(char *);

int main(){
  printf("%i\n", F);
  read_move(NULL);
  return 0;
} 

//Reads a Capcom notation move
int read_move(move_t m){
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
  if(!atk) {
    perror("index:");
    exit(1);
  }
  atk[0] = 0;
  atk++;

  printf("dir is %i\n", strtodir(dir));
  printf("atk is %i\n", strtoatk(atk));

  free(line);
  return 0;
}
