#ifndef _SIMPLESHELL_H_
#define _SIMPLESHELL_H_

#include "macro.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* pointers to the "environment," which is an array of pointers to strings. */
extern char **environ;


/**
 * struct data - Struct that Contains All Relevant Data on Runtime
 * @av: Arg Vector
 * @input: Command Line Written By User
 * @args: Token's of CMD Line
 * @status: Last Status of shell
 * @counter: Lines Counter
 * @_environ: Environ Var
 * @pid: Process ID of Shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - Singly Linked_list
 * @separator: ; | &
 * @next: Next Node
 * Description: Singly Linked_list to Store Separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - Singly Linked_list
 * @line: CMD Line
 * @next: Next Node
 * Description: Single Linked_list to Store CMD lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - Single Linked_list
 * @len_var: Lengt of the Var
 * @val: Val of the Var
 * @len_val: Lengt of the Val
 * @next: Next Node
 * Description: Singly linked_list to Store Var
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_t
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* lists_1.c */
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);

/* lists_2.c */
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

/* string_1.c */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* memory.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* string_2.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* string_3.c */
void rev_string(char *s);

/* synt_err.c */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(data_shell *datash, char *input, int i, int bool);
int check_syntax_error(data_shell *datash, char *input);

/* sim_shell_loop.c */
char *without_comment(char *in);
void shell_loop(data_shell *datash);

/* read_line_sh.c */
char *read_line(int *i_eof);

/* split_shell.c */
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);

/* rep_var_sh.c */
void check_env(r_var **h, char *in, data_shell *data);
int check_vars(r_var **h, char *in, char *st, data_shell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, data_shell *datash);

/* get_line_shell.c */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t k);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* exec_line_shell.c */
int exec_line_sh(data_shell *datash);

/* command_exe.c */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);

/* environ1.c */
char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);

/* environ2.c */
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, data_shell *datash);
int _setenv_sh(data_shell *datash);
int _unsetenv_sh(data_shell *datash);

/* command.c */
void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);

/* command_shell.c */
int cd_shell(data_shell *datash);

/* get_builtin_sh.c */
int (*get_builtin(char *cmd))(data_shell *datash);

/* exit_sim_shell.c */
int exit_shell(data_shell *datash);

/* built_in.c */
int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

/* error_1.c */
char *strcat_cd(data_shell *, char *, char *, char *);
char *error_get_cd(data_shell *datash);
char *error_not_found(data_shell *datash);
char *error_exit_shell(data_shell *datash);

/* error_2.c */
char *error_get_alias(char **args);
char *error_env(data_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(data_shell *datash);


/* get_error_shell.c */
int get_error_sh(data_shell *datash, int eval);

/* get_sigint_shell.c */
void get_sigint(int sig);

/* help_1.c */
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);

/* help_2.c */
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

/* get_help_sh.c */
int get_help_sh(data_shell *datash);

#endif
