/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:39:33 by htsang            #+#    #+#             */
/*   Updated: 2023/01/09 00:45:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lexer.h"

t_pipex_lexer_node	*free_lexer(t_pipex_lexer_node *lexer)
{
	t_pipex_lexer_node	*last_lexer;

	while (lexer)
	{
		last_lexer = lexer;
		lexer = lexer->next;
		free(last_lexer);
	}
	return (NULL);
}

static t_pipex_lexer_node	*lexer_new_node(size_t length)
{
	t_pipex_lexer_node	*lexer;

	lexer = malloc(sizeof(t_pipex_lexer_node));
	if (!lexer)
	{
		return (NULL);
	}
	lexer->length = length;
	lexer->next = NULL;
	return (lexer);
}

/**
 * @brief Converts a string representing a command to an intimediate
 * lexer linked list. Eventually the linked list will be handed to
 * the converter to convert it into an array of string, each representing
 * an command argument. This function calls different consumers, to consume
 * quotes, characters, and escape characters. Space will be used as
 * delimiter between command arguments.
 * @param command_args The command arguments represented in plain text.
 * @return The head of a lexer linked list
 */
t_pipex_lexer_node	*lex_command(const char *command_args)
{
	t_pipex_lexer_node	*lexer_head;
	t_pipex_lexer_node	*lexer;

	lexer_head = lexer_new_node(0);
	if (!lexer_head)
	{
		return (NULL);
	}
	ignore_spaces(&command_args);
	lexer = lexer_head;
	while (*command_args)
	{
		lexer->next = lexer_new_node(0);
		if (!lexer->next)
		{
			return (free_lexer(lexer_head));
		}
		lexer = consume_command_arg(&command_args, lexer->next);
		if (!lexer)
		{
			return (free_lexer(lexer_head));
		}
		(lexer_head->length)++;
	}
	return (lexer_head);
}
