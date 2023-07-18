#include "main.h"
/**
 * _isalpha - checks for lowercase character
 * @c: parameter
 * Return: 1 if the 'c' character is lowercase, 0 otherwise
 */
int _isalpha(int c)
{
if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
{
return (1);
}
return (0);
}
