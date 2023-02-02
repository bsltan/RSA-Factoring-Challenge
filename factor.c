#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - factorize numbers in to 2 #s from a file
 * @argc: # of parameters passed to main
 * @argv: array of parameters
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	long int i, num;

	if (argc != 2)
		exit(EXIT_FAILURE);

	fp = fopen(argv[1], "r");
	if  (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		line[read] = '\0';
		num = atol(line);

		i = 2;
		while (num % i != 0)
			i += 1;

		printf("%s=%li*%li\n", line, i, num / i);
	}

	fclose(fp);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
