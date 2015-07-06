#ifndef _DEF_H_
#define _DEF_H_

//All buttons for attacks
enum attack {LP = 1, MP = 2, HP = 3, 
	     LK = 4, MK = 5, HK = 6,
             P = 7, K = 8,
	     THROW = 14, //LP + LK
	     NONE = 0
            };

//All buttons for movements
enum direction {CB = 1, C = 2, CF = 3, 
		B = 4, S = 5, F = 6, 
		UB = 7, U = 8, UF = 9,
		QCF = 236, //C + CF + F
		QCB = 214, //C + CB + B
		HCF = 41236, //B + CB + C + CF + F
		HCB = 63214, //F + CF + C + CB + B
		DP = 523, //F + C + CF             
		CANCEL = -1,
               };

enum atk_type {NORMAL = 0, SPECIAL = 1, SUPER = 2};
enum bool {FALSE = 0, TRUE = 1};

typedef enum attack attack_t;
typedef enum direction direction_t;
typedef enum atk_type atk_type_t;
typedef enum bool bool_t;

/* Struct to document a singular movement */
struct Move {
  direction_t direction;
  attack_t attack;
  atk_type_t type;
  int n_startup_frames, n_on_hit_frames, n_on_block_frames;
};

typedef struct Move* Move_t;

/* List of moves makes a combo */
typedef struct Combo_node* Combo;

struct Combo_node {
  Move_t m;
  char *note;
  Combo next;
};

/* Holds info for a character */
struct Character{
  unsigned int n_moves, n_combos;
  char *name;
  struct Move* move_list;
  Combo* combo_list;
};

/* UTILITY FUNCTIONS */

int toupperstr(char *, int);
direction_t strtodir(char *);
attack_t strtoatk(char *);
char* dirtostr(direction_t, char *);
char* atktostr(attack_t, char *);

Move_t alloc_move(void);
void print_move(Move_t);
void print_move_numerical(Move_t);
void print_move_raw(Move_t);

Combo init_combo(Move_t, char*);
void add_move_to_combo(Move_t m, char*, Combo prev);
void print_combo(Combo);
void print_combo_numerical(Combo);
void print_combo_raw(Combo);
void free_combo(Combo);

/* PARSING COMBOS */

int read_move(Move_t, char*);
Combo read_combo(void);

#endif /* _DEF_H_ */
