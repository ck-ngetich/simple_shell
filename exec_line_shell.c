#include "simpleshell.h"

/**
 * exec_line_sh - Discover Builtin's and Command's.
 *
 * @datash: Data Relevant (args)
 * Return: 1 on Success.
 */
int exec_line_sh(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
