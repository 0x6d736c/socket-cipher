#define MAX (122)
#define MIN (65)


int inbounds(char c, int shift);
char encrypt(char c, int shift);
char decrypt(char c, int shift);
char * strencrypt(char * str, int shift);
char * strdecrypt(char * str, int shift);