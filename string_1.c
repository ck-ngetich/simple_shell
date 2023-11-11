#include "main.h"

/**
 * _strcat - function to concatenate two strings
 * @dest: the destination of the copied string
 * @src: the source of string
 * Return: the dest
 */

char *_strcat(char *dest, const char *src)
{
int i;
int j;

for (i = 0; dest[i] != '\0'; i++)
;

for (j = 0; src[j] != '\0'; j++)
{
dest[i] = src[j];
i++;
}

dest[i] = '\0';
return (dest);
}

/**
 * *_strcpy - function that copies the string pointed to by source.
 * @dest: the destination of the copied str
 * @src:  the source of string
 * Return: the destination.
 */

char *_strcpy(char *dest, char *src)
{

size_t a;

for (a = 0; src[a] != '\0'; a++)
{
dest[a] = src[a];
}
dest[a] = '\0';

return (dest);
}

/**
 * _strcmp - is a function  that compares two strings.
 * @s1: string1
 * @s2: string2
 * Return: 0.
 */

int _strcmp(char *s1, char *s2)
{
int i;

for (i = 0; s1[i] == s2[i] && s1[i]; i++)
;

if (s1[i] > s2[i])
return (1);
if (s1[i] < s2[i])
return (-1);
return (0);
}

/**
 * _strchr - is a funtion to locates a character in a string
 * @s: string to input
 * @c: character to use
 * Return: the pointer
 */

char *_strchr(char *s, char c)
{
unsigned int i = 0;

for (; *(s + i) != '\0'; i++)
if (*(s + i) == c)
return (s + i);
if (*(s + i) == c)
return (s + i);
return ('\0');
}
/**
 * _strspn - is a function that gets the length of a prefix substring.
 * @s: segment to start with
 * @accept: bytes accepted
 * Return: No. of accepted bytes.
 */

int _strspn(char *s, char *accept)
{
int i, j, bool;

for (i = 0; *(s + i) != '\0'; i++)
{
bool = 1;
for (j = 0; *(accept + j) != '\0'; j++)
{
if (*(s + i) == *(accept + j))
{
bool = 0;
break;
}
}
if (bool == 1)
break;
}
return (i);
}

