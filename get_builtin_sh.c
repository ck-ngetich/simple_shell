#include "simpleshell.h"

/**
 * get_builtin - Builtin that Pairs the cmd in the Args
 * @cmd: command
 * Return: Function pointer of the builtin cmd
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help_sh },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}
