#include "main.h"

/**
 * add_sep_node_end -function that  adds a separator found
 * at the end of the list.
 * @head: head linked_list.
 * @sep: the separator found
 * Return: address of linked_list head.
 */

sep_list *add_sep_node_end(sep_list **head, char sep)
{
sep_list *new, *temp;

new = malloc(sizeof(sep_list));
if (new == NULL)
return (NULL);

new->separator = sep;
new->next = NULL;
temp = *head;

if (temp == NULL)
{
*head = new;
}
else
{
while (temp->next != NULL)
temp = temp->next;
temp->next = new;
}

return (*head);
}

/**
 * free_sep_list - function that frees this list
 * @head: head of  linked_list.
 * Return: nothing
 */

void free_sep_list(sep_list **head)
{
sep_list *temp;
sep_list *curr;

if (head != NULL)
{
curr = *head;
while ((temp = curr) != NULL)
{
curr = curr->next;
free(temp);
}
*head = NULL;
}
}

/**
 * add_line_node_end - function that adds a command line
 * at the end of list
 * @head: head of linked list.
 * @line: cmd line.
 * Return: address of head of the list
 */

line_list *add_line_node_end(line_list **head, char *line)
{
line_list *new, *temp;

new = malloc(sizeof(line_list));
if (new == NULL)
return (NULL);

new->line = line;
new->next = NULL;
temp = *head;

if (temp == NULL)
{
*head = new;
}
else
{
while (temp->next != NULL)
temp = temp->next;
temp->next = new;
}

return (*head);
}

/**
 * free_line_list -  function that frees line_list
 * @head: head of linked list.
 * Return: nothing
 */

void free_line_list(line_list **head)
{
line_list *temp;
line_list *curr;

if (head != NULL)
{
curr = *head;
while ((temp = curr) != NULL)
{
curr = curr->next;
free(temp);
}
*head = NULL;
}
}
