/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:06:53 by htsang            #+#    #+#             */
/*   Updated: 2023/01/03 19:51:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lexer.h"

static char	**free_command(char **split_command, size_t count)
{
	if (count > 0)
	{
		count--;
		while (count)
		{
			free(split_command[count]);
			count--;
		}
		free(split_command[0]);
	}
	free(split_command);
	return (NULL);
}

static int	fill_quoted_string(char **split_command, \
const char **command_args, t_pipex_lexer_node *lexer)
{
	size_t	i;

	*split_command = malloc(lexer->length - 1);
	if (!(*split_command))
	{
		return (1);
	}
	(*split_command)[lexer->length - 2] = 0;
	i = 0;
	(*command_args)++;
	while (i < lexer->length - 2)
	{
		(*split_command)[i] = **command_args;
		i++;
		(*command_args)++;
	}
	(*command_args)++;
	ignore_spaces(command_args);
	return (0);
}

static int	fill_default(char **split_command, \
const char **command_args, t_pipex_lexer_node *lexer)
{
	size_t	i;

	*split_command = malloc(lexer->length + 1);
	if (!(*split_command))
	{
		return (1);
	}
	(*split_command)[lexer->length] = 0;
	i = 0;
	while (i < lexer->length)
	{
		if (**command_args != '\\')
		{
			(*split_command)[i] = **command_args;
			i++;
		}
		(*command_args)++;
	}
	ignore_spaces(command_args);
	return (0);
}

static int	fill_split_command(char **split_command, \
const char **command_args, t_pipex_lexer_node *lexer)
{
	if (ft_strchr("\'\"", **command_args) && \
	ft_strchr("\'\"", *(*command_args + lexer->length)))
	{
		return (fill_quoted_string(split_command, command_args, lexer));
	}
	return (fill_default(split_command, command_args, lexer));
}

char	**to_split_command(const char *command_args, t_pipex_lexer_node *lexer)
{
	t_pipex_lexer_node	*lexer_head;
	size_t				i;
	char				**split_command;

	if (!lexer)
		return (NULL);
	lexer_head = lexer;
	split_command = malloc((lexer_head->length + 1) * sizeof(char *));
	if (!split_command)
	{
		return (free_lexer(lexer_head), NULL);
	}
	lexer = lexer->next;
	split_command[lexer_head->length] = 0;
	i = 0;
	ignore_spaces(&command_args);
	while (i < lexer_head->length)
	{
		if (fill_split_command(&split_command[i++], &command_args, lexer))
		{
			return (free_lexer(lexer_head), free_command(split_command, i + 1));
		}
		lexer = lexer->next;
	}
	return (free_lexer(lexer_head), split_command);
}
