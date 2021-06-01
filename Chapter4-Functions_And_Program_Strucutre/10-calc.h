#define NUMBER '0' /* signal that a number was found*/
#define VARSET '1'
#define VARGET '2'

int getop(char s[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void clear(void);
double last(void);
void swap(void);

double var_get(int varindex);
void var_set(int varindex, double number);