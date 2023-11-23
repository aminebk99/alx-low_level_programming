#include "main.h"
/**
 * binary_to_uint - converter dyal munber int
 * @b: string fin kayn num
 * Return: lhadak  numb
 */
unsigned int binary_to_uint(const char *b)
{
int i;
unsigned int af_val = 0;
if (!b)
return (0);
for (i = 0; b[i]; i++)
{
if (b[i] < '0' || b[i] > '1')
return (0);
af_val = 2 * af_val + (b[i] - '0');
}
return (af_val);
}
