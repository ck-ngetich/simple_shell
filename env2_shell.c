#include "simpleshell.h"

/**
 * copy_info - Duplicates Info to Create
 * a New Environ or Alias
 * @name: Name (Environ or Alias)
 * @value: Value (Environ or Alias)
 *
 * Return: New Environ or Alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - Sets an Environ Var
 *
 * @name: Name of Environ Var
 * @value: Value of Environ Var
 * @datash: Data Struct (Env)
 * Return: No Return
 */
void set_env(char *name, char *value, data_shell *datash)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; datash->_environ[i]; i++)
	{
		var_env = _strdup(datash->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(datash->_environ[i]);
			datash->_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash->_environ = _reallocdp(datash->_environ, i, sizeof(char *) * (i + 2));
	datash->_environ[i] = copy_info(name, value);
	datash->_environ[i + 1] = NULL;
}

/**
 * _setenv - Checks the Name of Environ Var
 * against the passed name.
 * @datash: data relevant (Environ Name and Environ Val)
 *
 * Return: 1 on Success.
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv - An Environ Var is Deleted
 *
 * @datash: data relevant (Environ Name)
 *
 * Return: 1 on Success.
 */
int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (datash->args[1] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}
	k = -1;
	for (i = 0; datash->_environ[i]; i++)
	{
		var_env = _strdup(datash->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, datash->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_error(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->_environ[i]; i++)
	{
		if (i != o)
		{
			realloc_environ[j] = datash->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(datash->_environ[k]);
i	free(datash->_environ);
	datash->_environ = realloc_environ;
	return (1);
}
