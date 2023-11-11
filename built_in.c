#include "main.h"

/**
 * get_len - a function to obtain the length of a number
 * @n:integer number
 * Return: the length  of a number entered.
 */
int get_len(int n)
{
unsigned int n1;
int lenght = 1;

if (n < 0)
{
lenght++;
n1 = n * -1;
}
else
{
n1 = n;
}
while (n1 > 9)
{
lenght++;
n1 = n1 / 10;
														}

return (lenght);
}

/**
 * aux_itoa - is a function converts integer entered into a string.
 * @n: integer number
 * Return: string
 */

char *aux_itoa(int n)
{
unsigned int n1;
int lenght = get_len(n);
char *buffer;

buffer = malloc(sizeof(char) * (lenght + 1));
if (buffer == 0)
return (NULL);

*(buffer + lenght) = '\0';

if (n < 0)
{
n1 = n * -1;
buffer[0] = '-';
}
else
{
n1 = n;
}

lenght--;
do {
*(buffer + lenght) = (n1 % 10) + '0';
n1 = n1 / 10;
lenght--;
}
while (n1 > 0)
;
return (buffer);
}

/**
 * _atoi - is a function to converts string to an integer number
 * @s: string entered.
 * Return: integer number
 */

int _atoi(char *s)
{
unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

while (*(s + count) != '\0')
{
if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
break;

if (*(s + count) == '-')
pn *= -1;

if ((*(s + count) >= '0') && (*(s + count) <= '9'))
{
if (size > 0)
m *= 10;
size++;
}
count++;
}

for (i = count - size; i < count; i++)
{
oi = oi + ((*(s + i) - 48) * m);
m /= 10;
}
return (oi *pn);
}

