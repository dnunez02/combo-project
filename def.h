#ifndef _DEF_H_
#define _DEF_H_

//All buttons for attacks
enum attack_t {LP = 1, MP = 2, HP = 3, 
	       LK = 4, MK = 5, HK = 6,
               P = 7, K = 8,
	       NONE = 0};

//All buttons for movements
enum direction_t {CB = 1, C = 2, CF = 3, 
		  B = 4, S = 5, F = 6, 
		  UB = 7, U = 8, UF = 9};

static const int QCF = 236; //C + CF + F
static const int QCB = 214; //C + CB + B
static const int HCF = 41236; //B + CB + C + CF + F
static const int HCB = 63214; //F + CF + C + CB + B
static const int DP = 523; //F + C + CF

static const int THROW = 14; //LP + LK

static const int CANCEL = -1;

/* Struct to document a singular movement */
struct Move {
  int direction;
  int attack;
};

typedef struct Move* Move_t;

/* List of moves makes a combo */
typedef struct Combo_node* Combo;

struct Combo_node {
  Move_t m;
  Combo *next;
};

/* UTILITY FUNCTIONS */

int toupperstr(char *, int);
int strtodir(char *);
int strtoatk(char *);
void print_move(Move_t);

#endif /* _DEF_H_ */
