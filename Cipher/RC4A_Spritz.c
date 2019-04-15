/*RC4A_Spritz function implementation*/

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "Core.h"

// Key scheduling algorithm
void KSA (unsigned char *key, unsigned char S[256])
{
	for (int i = 0; i < 256; i++)
		S[i] = i;

	int j = 0;

	for (int i = 0; i < 256; i++)
	{
		j = (j + S[i] + key[i % strlen(key)]) % 256;
		swap (&S[i], &S[j]);
	}
	return;
}

// RC4A_SPRITZ is a combination of RC4A and SPRITZ; two of updated version of RC4
void RC4A_SPRITZ (unsigned char S1[256], unsigned char S2[256], unsigned char *plaintext, unsigned char *ciphertext)
{
	int i = 0;
	int j1 = 0, j2 = 0;
	int k1 = 0, k2 = 0;
	int w1 = 0, w2 = 0;
	int z1 = 0, z2 = 0;

	srand(time(NULL));

	for (int n = 0; n < strlen(plaintext); n++)
	{
		do
		{
			w1 = rand() % 256 + 1; // w1 is relatively prime to S1 size; 256
		} while (GCD(w1,256) != 1);

		i = (i + w1) % 256;
		j1 = (k1 + S1[j1] + S1[i]) % 256;
		k1 = (k1 + i + S1[j1]) % 256;
		swap (&S1[i], &S1[j1]);
		z1 = S2[(j1 + S1[i + S1[z1 + k1]]) % 256];

		ciphertext[n] = z1^plaintext[n];
	}
	
	for (int k = 0; k < strlen(ciphertext); k++)
	{
		do
		{
			w2 = rand() % 256 + 1; // w2 is relatively prime to S2 size; 256
		} while (GCD(w2,256) != 1);

		i = (i + w2) % 256;
		j2 = (k2 + S2[j2] + S2[i]) % 256;
		k2 = (k2 + i + S2[j2]) % 256;
		swap (&S2[i], &S2[j2]);
		z2 = S1[(j2 + S2[i + S2[z2 + k2]]) % 256];

		ciphertext[k] = z2^ciphertext[k];
	}
	return;
}

void OUROBOROS_Encrypt (unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext)
{
	unsigned char S1[256];
	unsigned char S2[256];

	KSA (key, S1);
	KSA (key, S2);

	RC4A_SPRITZ (S1, S2, plaintext, ciphertext);

	return;
}

unsigned char *OUROBOROS_Key() // Generate randomly the key. Here the key is 256 Bytes long.
{
	srand(time(NULL));
	unsigned char *Key = malloc(sizeof(unsigned char) * 256);
	assert (Key != NULL);

	for (int i = 0; i < 256; i++)
	{
		int random = rand() % 2;
		int key = rand() % 26;
		if (random == 0)
			Key[i] = (char)((key-65) % 26 + 65);
		else if (random == 1)
			Key[i] = (char)((key-97) % 26 + 97);
	}
	return Key;
}

