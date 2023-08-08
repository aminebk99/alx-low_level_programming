#include <stdlib.h>
#include "main.h"

/**
 * argstostr - its goal is to collect all the arguments in the program
 * @ac: considered to be the input  of arguments
 * @av: is the input strin
 *
 * Return: Here we depend on the Condition
 */
char *argstostr(int ac, char **av)
{
	int j;
	int i;
	int a;
	int size;
	char *new;

	if (ac == 0 || av == NULL)
		return (NULL);
	size = ac;
	for (j = 0; j < ac; j++)
	{
		for (i = 0; av[j][i] != '\0'; i++)
		{
			size++;
		}
	}
	new = malloc(size + 1 * sizeof(char));
	if (new == NULL)
		return (NULL);
	a = 0;
	for (j = 0; j < ac; j++)
	{
		for (i = 0; av[j][i] != '\0'; i++)
		{
			new[a] = av[j][i];
			a++;
		}
		new[a] = '\n';
		a++;
	}
	return (new);
}
