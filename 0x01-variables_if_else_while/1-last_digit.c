#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */

/* betty style doc for function main goes there */
/**
 * this program determines if a is positive or negative or,zero
 * Return: 0
 */
int main(void)
{
int n;
int a;
srand(time(0));
n = rand() - RAND_MAX / 2;
/* your code goes there */
a = n % 10;
if (a > 5)
{
printf("and is greater than 5\n", n, a);
}
else if (a < 6 && a != 0)
{
printf("and is less than 6 and not 0\n", n, a);
}
else
{
printf("and is 0", n, a);
}
return (0);
}
