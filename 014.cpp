#include <iostream>
#include <stdlib.h>
using namespace std;

unsigned long calculateCollatzSequenceLenght (/*unsigned long * lengths, */unsigned long number)
{
	unsigned long length = 1;

	while (number != 1)
	{
		length++;

		if (number % 2 == 0) // number is even
		{
			number = number / 2;
		}
		else // number is odd
		{
			number = (number * 3) + 1;
		}
	}

	return length;
}

int main (int argc, char *argv[])
{
	if (argc == 1)
	{
		exit (-1);
	}

	unsigned long iterations = stoi(argv[1]);
	unsigned long bestNumber = 0;
	unsigned long bestLength = 0;
	unsigned long actualLength = 0;

	printf ("+++++++++++++++\n");
	printf ("Running %lu iterations\n", iterations);
	printf ("+++++++++++++++\n");

	for (unsigned long i = 1; i <= iterations; ++i)
	{
		actualLength = calculateCollatzSequenceLenght (i);
		if (actualLength >= bestLength)
		{
			bestLength = actualLength;
			bestNumber = i;
		}
	}

	printf("Best number: %lu\n", bestNumber);
	printf("Maximum length: %lu\n", bestLength);

	return 0;
}