#ifndef HEADER_h_
#define HEADER_h_

int GCD (int a, int b);

void swap (unsigned char *a, unsigned char *b);

unsigned char *swap_character (unsigned char *text);

void KSA (unsigned char *key, unsigned char S[256]);

void PRG (unsigned char S1[256], unsigned char S2[256], unsigned char *plaintext, unsigned char *ciphertext);

void OUROBOROS_Encrypt (unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext);

unsigned char *OUROBOROS_Key();


#endif
