#include "simpleshell.h"

/**
 * add_rvar_node -function that  adds a variable
 * at the end linked_list
 * @head: head of linked_list.
 * @lvar: length of variable.
 * @val: value of variable.
 * @lval: length of the value of variable
 * Return: address of the head of linked_list
 */

r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
r_var *new, *temp;

new = malloc(sizeof(r_var));
if (new == NULL)
return (NULL);

new->len_var = lvar;
new->val = val;
new->len_val = lval;

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
 * free_rvar_list - function that frees a r_var linked_ list
 * @head: head of the linked list.
 * Return: nothing
 */

void free_rvar_list(r_var **head)
{
r_var *temp;
r_var *curr;

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
