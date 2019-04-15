/*Andry Rafam Andrianjafy - February 2019

Ouroboros: Multiple encryption text program based on RC4A_SPRITZ, SHA 256 and SHA 384.

Implemented under Linux Ubuntu 16.04 LTS operating system - GCC Version 6.5.0 GDB Version 8.2*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <openssl/sha.h>
#include "Core.h"
#include "Colors.h"

// Driver program			
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\nUsage: %s < Plaintext > (If a string; put inside quotation marks)\n\n", argv[0]);
		return -1;
	}
	
	system("clear");

	printf(Red "\n\n=================== OUROBOROS ENCRYPTION PROGRAM, Andry Rafam ====================\n\n" Reset);
	
	fprintf(stdout, "Clear message -> %s\n\n", argv[1]);	
	// Applying RC4_Spritz on stage0
	unsigned char *stage1 = malloc(sizeof(int) * strlen(argv[1]));
	assert (stage1 != NULL);
	OUROBOROS_Encrypt (argv[1], OUROBOROS_Key(), stage1);

	// Applying SHA-512 on stage1
	unsigned char *stage2 = malloc(sizeof(unsigned char) * SHA384_DIGEST_LENGTH);
	assert (stage2 != NULL);
	stage2 = SHA384(stage1, strlen(stage1), 0);
	
	// Applying SHA-384 on stage2
	unsigned char *stage3 = malloc(sizeof(unsigned char) * SHA256_DIGEST_LENGTH);
	assert (stage3 != NULL);
	stage3 = SHA256(stage2, SHA384_DIGEST_LENGTH, 0); 

	printf("All stage completed \n\n");
	
	printf(Cyan "[ ENCRYPTED MESSAGE ] >> " Reset);
	
	unsigned char *result = malloc(sizeof(unsigned char) * (SHA256_DIGEST_LENGTH + 1));
	assert (result != NULL);
	memcpy(result, swap_character(stage3), SHA256_DIGEST_LENGTH + 1);
	
	for (int y = 0; y < SHA256_DIGEST_LENGTH; y++)
		printf("%02x", *(result+y));
	printf(Reset "\n\n");

	free(result);

	return EXIT_SUCCESS;
}


	
