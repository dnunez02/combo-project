#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "def.h"

//Make a string uppercase
int toupperstr(char *str, int len){
  int i;
  for(i = 0; i < len; ++i){
    str[i] = toupper(str[i]);
  }
  return 0;
}

int strtodir(char *str){
  if(!str) {
    return NONE;
  }
  if(!strcasecmp("B", str)){
    return B;
  } else if(!strcasecmp("C", str)){
    return C;
  } else if(!strcasecmp("CB", str)){
    return CB;
  } else if(!strcasecmp("CF", str)){
    return CF;
  } else if(!strcasecmp("DP", str)){
    return DP;
  } else if(!strcasecmp("F", str)){
    return F;
  } else if(!strcasecmp("HCB", str)){
    return HCB;
  } else if(!strcasecmp("HCF", str)){
    return HCF;
  } else if(!strcasecmp("QCB", str)){
    return QCB;
  } else if(!strcasecmp("QCF", str)){
    return QCF;
  } else if(!strcasecmp("S", str)){
    return S;
  } else if(!strcasecmp("J", str) || !strcasecmp("U", str)){
    return U;
  } else if(!strcasecmp("UB", str)){
    return UB;
  } else if(!strcasecmp("UF", str)){
    return UF;
  } else if(!strcasecmp("XX", str)){
    return CANCEL;
  } else {
    return S;
  }
}

int strtoatk(char *str){
  char *split;

  if(!str){
    return NONE;
  }

  //Deal with multiple attack buttons
  if((split = rindex(str, '+'))){
    int fst, snd;
    split[0] = 0;
    split++;
    fst = strtoatk(str);
    snd = strtoatk(split);
    return (fst * 10) + snd;
  }

  if(!strcasecmp("LP", str)){
    return LP;
  } else if(!strcasecmp("MP", str)){
    return MP;
  } else if(!strcasecmp("HP", str)){
    return HP;
  } else if(!strcasecmp("LK", str)){
    return LK;
  } else if(!strcasecmp("MK", str)){
    return MK;
  } else if(!strcasecmp("HK", str)){
    return HK;
  } else {
    return NONE;
  }
}

void print_move(Move_t m){
  printf("dir is %i\n", m->direction);
  printf("atk is %i\n", m->attack);
}
