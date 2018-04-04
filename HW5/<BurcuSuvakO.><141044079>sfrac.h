#ifndef Sfrac_h
#define Sfrac_h

int num_size(int x);
void separate_num(int num,int *n,int size);
void convert_toint(char *x,int *num1,int *num2);
char *convert_tochar(char *x,int *num1,int *num2);
void gcd(int *n1,int *n2);
char *sfrac_simplify(char * n);
char * sfrac_add(char * n1, char * n2);
char * sfrac_sub(char * n1, char * n2);
char * sfrac_mult(char * n1, char * n2);
char * sfrac_div(char * n1, char * n2);
void sfrac_print(char *a1,char *n1,char *a2,char *n2,char *a3,char *n3,char *a4);

#endif
