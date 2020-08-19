#include "header.h"
/**
 *add_nodeint_end - adds a new node at the end of a listint_t list
 *@head: head of the list
 *@command: data
 *
 *Return: new_node address of the new created node
 */
commands *add_node_end(commands **head, char **command)
{
	commands *new_node;
	commands *aux;

	new_node = malloc(sizeof(commands));
	if (!new_node)
		return (NULL);
	new_node->split_command = command;
	new_node->next = NULL;
	if (!*head)
		*head = new_node;
	else
	{
		aux = *head;
		while (aux->next)
			aux = aux->next;
		aux->next = new_node;
	}

	return (new_node);
}
/**
 * split_buffer - allocate memory to buffer and separe words.
 * @header: pointer arguments structure.
 * Return: arguments (double pointer).
 */
void split_buffer(ssh *header)
{
	char delimiter[] = "\n", delimiter2[] = " \t", **aux = NULL;
	int i = 0;

	header->arguments = str_tok(header->buffer, delimiter);
	while (header->arguments[i])
	{
		if (header->arguments[i][0] != '\0')
		{
			aux = str_tok(header->arguments[i], delimiter2);
			add_node_end(&header->head_cmd, aux);
		}
		i++;
	}
}
/**
 * exit_ - finction with validation exit.
 * @header: take arguments structure.
 * @aux: take auxiliar pointer array.
 * @aux2: take auxiliar pointer array2.
 * Return: integer 0 or exit success.
 */
int exit_(ssh *header, char *aux, char **aux2)
{
	char **token = NULL, *copy = NULL;
	int EXIT_STATUS = 0;

	copy = str_cpy(copy, header->buffer, str_len(header->buffer));
	token = str_tok(copy, " \n\t\r\b\v\f");
	if (token[1] == NULL)
		EXIT_STATUS = 0;
	else
	{
		EXIT_STATUS = _atoi(token[1]);
		if (EXIT_STATUS < 0)
		{
			printf("%s: exit: Illegal number: %i\n",
				header->argv[0], EXIT_STATUS);
			free_malloc(token), free(copy);
			return (0);
		}
	}
	free(header->buffer), free_malloc(token), free(copy);
	free_malloc(header->arguments), free(header->OLD_WD), free_PWD(header);
	free_listint(header->head), free_commands(header);
	free(aux), free_malloc(aux2), free(header);
	exit(EXIT_STATUS);
}
/**
 * _env - take enviromen variable by the structure
 * @header: pointer structure values.
 * Return: 0 success.
 */
int _env(ssh *header)
{
	char **token = NULL, *copy = NULL;
	int i = 0;

	copy = str_cpy(copy, header->buffer, str_len(header->buffer));
	token = str_tok(copy, " \n\t\r\b\v\f");
	while (header->envp[i])
		printf("%s\n", header->envp[i]), i++;
	free_malloc(token), free(copy);

	return (0);
}
/**
 * check_buffer - check content buffer (words or NULL, etc.)
 * @buffer: buffer
 * @header: pointer to the structure.
 * Return: 1 or 0 and success.
 */
int check_buffer(char *buffer, ssh *header)
{
	comparison_id identifiers[] = {{"exit", exit_}, {"env", _env},
	{"cd", _cd}, {"setenv", _envset},
	{"unsetenv", _unsetenv}, {NULL, NULL}};
	char **token = NULL, *copy = NULL;
	int i = 0, aux = 1;

	copy = str_cpy(copy, buffer, str_len(buffer));
	token = str_tok(copy, " \n\t\r\b\v\f"); /* copy of split buffer */
	if (token[0] == NULL)
	{
		free_malloc(token), free(copy);
		return (0);
	}
	while (identifiers[i].comp)
	{
		if (!str_cmp(identifiers[i].comp, token[0], str_len(token[0])))
		{
			aux = identifiers[i].function_int(header, copy, token);
			break;
		}
		i++;
	}
	free_malloc(token), free(copy);
	return (aux);
}
