#ifndef _DEF_H_
#define _DEF_H_

//All buttons for attacks
enum attack_t {LP = 1 << 1, MP = 1 << 2, HP = 1 << 3, 
	       LK = 1 << 4, MK = 1 << 5, HK = 1 << 6,
	       NONE = 0};

//All buttons for movements
enum direction_t {CB = 1 << 1, C = 1 << 2, CF = 1 << 3, 
		  B = 1 << 4, S = 1 << 5, F = 1 << 6, 
		  UB = 1 << 7, U = 1 << 8, UF = 1 << 9};

static const int QCF = (C | CF | F);
static const int QCB = (C | CB | B);
static const int HCF = (B | CB | C | CF | F);
static const int HCB = (F | CF | C | CB | B);
static const int THROW = (LP | LK);
static const int DP = (C | F | CF);
static const int CANCEL = -1;

/* Struct to document a singular movement */
struct move {
  int direction;
  int attack;
};

typedef move* move_t;

/* UTILITY FUNCTIONS */

int toupperstr(char *, int);
int strtodir(char *);
int strtoatk(char *);

#endif /* _DEF_H_ */
