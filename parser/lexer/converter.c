/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:06:53 by htsang            #+#    #+#             */
/*   Updated: 2023/01/09 00:33:56 by htsang           ###   ########.fr       */
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

/**
 * @brief Converts from the lexer intermediate linked list to an array of string,
 * which can be plugged into the execve() function. This function calls the 
 * run_convert_copier() function to do the actually copying of bytes.
 * @param command_args memory address of a command string input by the user
 * @param lexer the lexer head
 * @return an array of string each represents an arguments of a command.
 */
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
