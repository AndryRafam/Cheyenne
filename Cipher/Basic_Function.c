/*All basic function used in the program*/

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

// Used in RC4A_Spritz function
int GCD (int a, int b)
{
	if (a > b)
	{
		if (a % b == 0)
			return b;
		else
			return GCD(b,a%b);
	}
	else if (b > a)
	{
		if (b % a == 0)
			return a;
		else
			return GCD(a,b%a);
	}
}

void swap (unsigned char *a, unsigned char *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// Swap the character of the clear message
unsigned char *swap_character (unsigned char *text)
{
	unsigned char *result = malloc(sizeof(unsigned char) * strlen(text));
	assert (result != NULL);

	if (strlen(text) % 2 == 0)
	{
		for (int i = 0; i < strlen(text); i += 2)
		{
			swap (&text[i], &text[i+1]);
			result[i] = text[i];
			result[i+1] = text[i+1];
		}
	}
	else
	{
		for (int i = 0; i < strlen(text) - 1; i += 2)
		{
			swap (&text[i], &text[i+1]);
			result[i] = text[i];
			result[i+1] = text[i+1];
		}
		result[strlen(text)-1] = text[strlen(text)-1];
	}
	return result;
}

char *salt () {
	unsigned char *string = malloc(sizeof(unsigned char) * 4);
	assert (string != 0);
	srand(time(0));
	int i = 0;

	while (i < 8) {
		int random = rand() % 2;
		int key = rand() % 26;

		if (random == 0)
			string[i] = (char)((key-65) % 26 + 65);
		else if (random == 1)
			string[i] = (char)((key-97) % 26 + 97);
		i += 1;
	}
	return string;
}


	

