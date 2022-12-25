/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:39:33 by htsang            #+#    #+#             */
/*   Updated: 2022/12/26 00:07:51 by htsang           ###   ########.fr       */
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
	while (*command_args)
	{
		lexer->next = lexer_new_node(0);
		lexer = consume_command_arg(&command_args, lexer->next);
		if (!lexer)
		{
			return (free_lexer(lexer_head));
		}
		(lexer_head->length)++;
	}
	return (lexer_head);
}
