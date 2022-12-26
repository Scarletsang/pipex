/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:06:53 by htsang            #+#    #+#             */
/*   Updated: 2022/12/26 23:12:41 by htsang           ###   ########.fr       */
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

static int	fill_split_command(char *split_command_arg, \
const char **command_args, t_pipex_lexer_node *lexer)
{
	split_command_arg = malloc(lexer->length + 1);
	if (!split_command_arg)
	{
		return (1);
	}
	split_command_arg[lexer->length] = 0;
	while (lexer->length > 0)
	{
		*split_command_arg = **command_args;
		split_command_arg++;
		(*command_args)++;
		lexer->length--;
	}
	ignore_spaces(command_args);
	return (0);
}

char	**to_split_command(const char *command_args, t_pipex_lexer_node *lexer)
{
	t_pipex_lexer_node	*lexer_head;
	size_t				i;
	char				**split_command;

	if (!lexer)
		return (NULL);
	lexer_head = lexer;
	split_command = malloc(lexer_head->length * sizeof(char *) + 1);
	if (!split_command)
	{
		return (free_lexer(lexer_head), NULL);
	}
	split_command[lexer_head->length - 1] = 0;
	i = 0;
	ignore_spaces(&command_args);
	while (i < lexer_head->length)
	{
		if (fill_split_command(split_command[i++], &command_args, lexer))
		{
			return (free_lexer(lexer_head), free_command(split_command, i));
		}
		lexer = lexer->next;
	}
	return (free_lexer(lexer_head), split_command);
}
