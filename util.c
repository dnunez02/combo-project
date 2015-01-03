#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

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

  //fprintf(stderr, "%s\n", str);
  char *split;

  //Deal with multiple attack buttons
  if((split = rindex(str, '+'))){
    int fst, snd;
    split[0] = 0;
    split++;

    fst = strtodir(str);
    snd = strtodir(split);

    return (fst * 10) + snd;
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
  } else if(!strcasecmp("P", str)){
    return P;
  } else if(!strcasecmp("K", str)){
    return K;
  } else {
    return NONE;
  }
}

char* dirtostr(int direction, char *l){
  if(!direction){
    return l;
  }

  int tmp = direction % 10;

  char *s, *ans;
  if(l){
    s = (char *)malloc((strlen(l) + 5) * sizeof(char));
  } else {
    s = (char *)malloc(3 * sizeof(char));
  }

  //case analysis
  switch(tmp){
  case 1: strncpy(s, "CB", 3); break;
  case 2: strncpy(s, "C", 2); break;
  case 3: strncpy(s, "CF", 3); break;
  case 4: strncpy(s, "B", 2); break;
  case 5: strncpy(s, "S", 2); break;
  case 6: strncpy(s, "F", 2); break;
  case 7: strncpy(s, "UB", 3); break;
  case 8: strncpy(s, "U", 2); break;
  case 9: strncpy(s, "UF", 3); break;
  default: s = ""; break;
  }

  if(l) {
    strncat(s, "+", 1);
    strncat(s, l, strlen(l));
  }
  ans = dirtostr(direction/10, s);
  if(s != ans) {
    free(s);
  }
  return ans;
}

char* atktostr(int attack, char *l){
  if(!attack){
    return l;
  }

  int tmp = attack % 10;

  char *s, *ans;
  if(l){
    s = (char *)malloc((strlen(l) + 4) * sizeof(char));
  } else {
    s = (char *)malloc(3 * sizeof(char));
  }

  //case analysis
  switch(tmp){
  case 1: strncpy(s, "LP", 3); break;
  case 2: strncpy(s, "MP", 3); break;
  case 3: strncpy(s, "HP", 3); break;
  case 4: strncpy(s, "LK", 3); break;
  case 5: strncpy(s, "MK", 3); break;
  case 6: strncpy(s, "HK", 3); break;
  case 7: strncpy(s, "P", 2); break;
  case 8: strncpy(s, "K", 2); break;
  default: s = ""; break;
  }

  if(l) {
    strncat(s, "+", 1);
    strncat(s, l, strlen(l));
  }
  ans = atktostr(attack/10, s);
  if(s != ans) free(s);
  return ans;
}

/* Move-specific utilities */

Move_t alloc_move(void){
  return (Move_t) malloc(sizeof(struct Move));
}

void print_move(Move_t m){
  char *dir = NULL;
  char *atk = NULL;

  dir = dirtostr(m->direction, NULL);
  atk = atktostr(m->attack, NULL);

  printf("%s.%s", dir, atk);

  if(dir) free(dir);
  if(atk) free(atk);
}

void print_move_numerical(Move_t m){
  char *atk;
  atk = atktostr(m->attack, NULL);

  printf("%i%s", m->direction, atk);

  if(atk) free(atk);
}

void print_move_raw(Move_t m){
  printf("dir is %i\n", m->direction);
  printf("atk is %i\n", m->attack);
}

/* Combo-specific utilities */

Combo init_combo(Move_t m){
  Combo tmp;
  tmp = (Combo) malloc(sizeof(struct Combo_node));
  tmp->m = m;
  tmp->next = NULL;
  return tmp;
}

void add_move_to_combo(Move_t m, Combo prev){
  Combo tmp;
  tmp = init_combo(m);
  prev->next = tmp;
}

void print_combo(Combo c){
  Combo tmp = c;
  while(tmp){
    print_move(tmp->m);
    tmp = tmp->next;
    if(tmp) printf(",");
  }
  printf("\n");
}

void print_combo_numerical(Combo c){
  Combo tmp = c;
  while(tmp){
    print_move_numerical(tmp->m);
    tmp = tmp->next;
    if(tmp) printf(",");
  }
  printf("\n");
}

void print_combo_raw(Combo c){
  Combo tmp = c;
  while(tmp){
    print_move_raw(tmp->m);
    tmp = tmp->next;
    if(tmp) printf(",");
  }
  printf("\n");
}

void free_combo(Combo c){
  Combo tmp;
  while(c){
    tmp = c->next;
    free(c->m);
    free(c);
    c = tmp;
  }
}
