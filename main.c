#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "cipher.h"

int parseshift(char * shift);
int parsemsg(char * msg);

int main(int argc, char * argv[]) {
    int shift = parseshift(argv[1]);        //Parse shift command
    char * msg = argv[2];                   //Get msg from CLI

    //TODO: 
    //1. If msg is empty, enter extended shell but save shift input.
    //2. If msg exists, ask for dest. address
    //3. If shift is empty, alert user, enter extended shell and require all new inputs.

    //Used for debugging purposes | Remove at end
    printf("Encrypted: %s\n", strencrypt(msg, shift));
    printf("Decrypted: %s\n", strdecrypt(msg, shift));

    return 0;
}
 
/* Checks CLI shift args for validity. Returns 0 if invalid. */
int parseshift(char * shift) {
    if (strlen(shift) < 3) return 0;
    if (shift[0] != '-') return 0;
    if (shift[1] != 's') return 0;

    //Copy shift address and increment by 2 to extract substring of ints
    char * shift_ptr = shift;
    shift_ptr += 2;

    return atoi(shift_ptr);
}

/* Checks CLI msg args. Returns 0 if doesn't exit.*/
int parsemsg(char * msg) {
    return strlen(msg) < 1;
}