#include "main.h"

/**
 * cmp_env_name - is a function that compares environment variables names
 * @nenv: name of the environment variable
 * @name: name passed
 * Return: 0 if are not equal. Another value if they are.
 */

int cmp_env_name(const char *nenv, const char *name)
{
int i;

for (i = 0; nenv[i] != '='; i++)
{
if (nenv[i] != name[i])
{
return (0);
}
}
return (i + 1);
}

/**
 * _getenv - is a function that  gives an environment variable
 * @name: name of environment variable
 * @_environ: variable of the environnment
 * Return: value of the environment variable and NULL otherwise
 */

char *_getenv(const char *name, char **_environ)
{
char *ptr_env;
int i, mov;
ptr_env = NULL;
mov = 0;

for (i = 0; _environ[i]; i++)
{
mov = cmp_env_name(_environ[i], name);
if (mov)
{
ptr_env = _environ[i];
break;
}
}
return (ptr_env + mov);
}

/**
 * _env -  is a function that prints the evironment variables
 * @datash: relevant data.
 * Return: 1 on success otherwise ruturn  NULL
 */

int _env(data_shell *datash)
{
int i, j;

for (i = 0; datash->_environ[i]; i++)
{
for (j = 0; datash->_environ[i][j]; j++)
;
write(STDOUT_FILENO, datash->_environ[i], j);
write(STDOUT_FILENO, "\n", 1);
}
datash->status = 0;

return (1);
}

