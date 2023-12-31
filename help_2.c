#include "simpleshell.h"

/**
 * aux_help - is a function that help information for the builtin help function
 * Return: nothing
 */

void aux_help(void)
{
char *help = "help: help [-dms] [pattern ...]\n";

write(STDOUT_FILENO, help, _strlen(help));
help = "\tDisplay information about builtin commands.\n ";
write(STDOUT_FILENO, help, _strlen(help));
help = "Displays brief summaries of builtin commands.\n";
write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_alias - is a function that help information
 * for the builtin alias function
 * Return: nothing
 */

void aux_help_alias(void)
{
char *help = "alias: alias [-p] [name[=value]...]\n";

write(STDOUT_FILENO, help, _strlen(help));
help = "\tDefine or display aliases.\n ";
write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_cd - is a function that help information
 * for the builtin alias function
 * Return: nothing
 */

void aux_help_cd(void)
{
char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

write(STDOUT_FILENO, help, _strlen(help));
help = "\tChange the shell working directory.\n ";
write(STDOUT_FILENO, help, _strlen(help));
}

