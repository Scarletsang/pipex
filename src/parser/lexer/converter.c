/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:06:53 by htsang            #+#    #+#             */
/*   Updated: 2023/01/06 00:28:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lexer.h"

const char	*get_escape_char(const char *str)
{
	if (*str == '\\')
	{
		return (str + 1);
	}
	return (NULL);
}

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
		if (run_converter_copier(&split_command[i++], &command_args, lexer))
		{
			return (free_lexer(lexer_head), free_command(split_command, i + 1));
		}
		lexer = lexer->next;
	}
	return (free_lexer(lexer_head), split_command);
}
