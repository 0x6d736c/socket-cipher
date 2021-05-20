#include "cipher.h"

/* Determine if character in bounds pre- and post-shift. */
int inbounds(char c, int shift) {
    //TODO: add check for >= 91 and <= 96
    int preshift = (c <= MAX) && (c >= MIN) && (c < 91 || c > 96);
    int postshift = ((c + shift) <= MAX) && ((c + shift) >= MIN) && (c + shift < 91 || c + shift > 96);
    return (preshift && postshift);
}

/* Encrypts character. Returns '-' if character out of bounds. */
char encrypt(char c, int shift) {
    if (!inbounds(c, shift)) return '-';
    return (c + shift);
}

/* Decrypts character. Returns '-' if character out of bounds. */
char decrypt(char c, int shift) {
    if (!inbounds(c, -shift)) return '-';
    return (c - shift);
}

/* Encrypts entire string. Replaces out of bounds characters with '-'. Done in-place. Original message consumed.*/
char * strencrypt(char * str, int shift) {
    char * strptr = str;

    while (*str != '\0') {
        *str = encrypt(*str, shift);
        ++str;
    }

    return strptr;
}

/* Decrypts entire string. Replaces out of bounds characters with '-'. Done-in place. Original message consumed.*/
char * strdecrypt(char * str, int shift) {
    char * strptr = str;

    while (*str != '\0') {
        *str = decrypt(*str, shift);
        ++str;
    }

    return strptr;
}

