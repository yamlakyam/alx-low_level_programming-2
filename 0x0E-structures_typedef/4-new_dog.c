#include "dog.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * *_strdup - return a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter.
 * @str: string
 * Return: 0
 */

char *_strdup(char *str)
{
int i, size;
char *m;

if (str == NULL)
	return (NULL);

for (size = 0; str[size] != '\0'; size++)
;

m = malloc(size * sizeof(*str));

if (!m)
	return (NULL);

for (i = 0; i <= size; i++)
	m[i] = str[i];

return (m);
}


/**
 * *new_dog - create a new dog
 * @name: string for name
 * @age: integer for age
 * @owner: string for owners
 * Return: a dog or NULL
 */


dog_t *new_dog(char *name, float age, char *owner)
{
struct dog *mydog;
mydog = malloc(sizeof(struct dog));

if (mydog == NULL)
	return (NULL);

mydog->name = _strdup(name);

if (!mydog->name)
{
	free(mydog->name);
	free(mydog);
	return (NULL);
}

mydog->owner = _strdup(owner);

if (mydog->owner == NULL)
{
	free(mydog->owner);
	free(mydog->name);
	free(mydog);
	return (NULL);
}

mydog->age = age;

return (mydog);
}
