#include "simpleshell.h"

/**
 * get_sigint - handle's the crtl + c call's in prompt
 * @sig: Signal Handler
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
