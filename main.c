#include "include/def.h"

int main(){
  Combo c;
  while((c = read_combo())){
    print_combo(c);
    free_combo(c);
  }
  return 0;
} 



