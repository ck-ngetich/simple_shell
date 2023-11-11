#include "simpleshell.h"

/**
 * _memcpy - function to copies information between void pointers.
 * @newptr: is the dest of  pointer.
 * @ptr: is the src pointer.
 * @size: size of new pointer.
 * Return: nothing
 */

void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
char *char_ptr = (char *)ptr;
char *char_newptr = (char *)newptr;
unsigned int i;

for (i = 0; i < size; i++)
char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - function to reallocates a memory block.
 * @ptr: pointer previously allocated
 * @old_size: size of the allocated space of pointer
 * @new_size: new size the new memory allocated
 * Return: pointer without changes if new_size == old_size otherwise NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *newptr;

if (ptr == NULL)
return (malloc(new_size));

if (new_size == 0)
{
free(ptr);
return (NULL);
}

if (new_size == old_size)
return (ptr);

newptr = malloc(new_size);
if (newptr == NULL)
return (NULL);

if (new_size < old_size)
_memcpy(newptr, ptr, new_size);
else
_memcpy(newptr, ptr, old_size);

free(ptr);
return (newptr);
}

/**
 * _reallocdp - function that reallocates a memory block of a double ptr.
 * @ptr: double pointer previously allocated.
 * @old_size: allocated space of double pointer
 * @new_size: new memory block to be allocated
 * Return: double pointer without changes if old_size == new_size else NULL
 */

char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
char **newptr;
unsigned int i;

if (ptr == NULL)
return (malloc(sizeof(char *) * new_size));

if (new_size == old_size)
return (ptr);

newptr = malloc(sizeof(char *) * new_size);
if (newptr == NULL)
return (NULL);

for (i = 0; i < old_size; i++)
newptr[i] = ptr[i];

free(ptr);

return (newptr);
}

