#include "header.h"
/**
 * _searchenv - take the pointer to an environment variable
 * @name: variable name.
 * Return: exist pointer to variable, or NULL.
 */
char *_searchenv(char *name)
{
	char **env;
	int len;

	env = environ;
	len = strlen(name);
	while (*env != NULL)
	{
		if (_strncmp(*env, name, len) == 0)
			return (*env);
		env++;
	}
	return (NULL);
}
/**
 * _envset - add or modify environment var.
 * @header: take structure data.
 * Return: name of variable.
 */
int _envset(ssh *header)
{
	char *nvar = NULL, *name = NULL, *copy = NULL, **tok = NULL;
	char *envnew = NULL;
	int len = 0, len2 = 0;

	copy = str_cpy(copy, header->buffer, str_len(header->buffer));
	tok = str_tok(copy, " \n\t\r\b\v\f"), name = tok[1], nvar = tok[2];
	len = str_len(name), len2 = str_len(nvar);
	if (nvar == NULL || name == NULL) /* setenv hola=mundo */
	{
		_printf("Error usage");
		return (0);
	}
	if (_searchenv(name) == NULL)
	{
		envnew = malloc(sizeof(char) * (len + len2 + 2));
		if (!envnew)
		{
			free(envnew), free_malloc(tok), free(copy);
			_printf("Error: can not allocate memory\n");
			exit(EXIT_FAILURE);
		}
		if (!addenv(header, name, nvar, envnew))
		{
			free_malloc(tok), free(copy);
			return (EXIT_SUCCESS);
		}
	}
	else
	{
		if (nvar == NULL)
			;
		else
		{
			owrenv(header, name, nvar);
			free_malloc(tok), free(copy);
			return (EXIT_SUCCESS);
		}
	}
	free_malloc(tok), free(copy);
	return (EXIT_SUCCESS);
}
/**
 * _searchenv2 - take the pointer to an environment variable
 * @name: variable name.
 * Return: integer.
 */
int _searchenv2(char *name)
{
	char **env;
	int len = 0, i = 0;

	env = environ;
	len = strlen(name);
	while (env[i] != NULL)
	{
		if (_strncmp(env[i], name, len) == 0)
			return (i);
		i++;
	}
	return (0);
}
