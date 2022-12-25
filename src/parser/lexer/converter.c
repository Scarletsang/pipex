/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:06:53 by htsang            #+#    #+#             */
/*   Updated: 2022/12/26 00:22:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lexer.h"

char	**to_split_command(const char *command_args, t_pipex_lexer_node *lexer)
{
	t_pipex_lexer_node	*lexer_head;
	size_t				index;
	char				**split_command;

	if (!lexer)
	{
		return (NULL);
	}
	lexer_head = lexer;
	split_command = malloc(lexer_head->length * sizeof(char *) + 1);
	if (!split_command)
	{
		return (free_lexer(lexer_head));
	}
	split_command[lexer_head->length - 1] = NULL;
	index = 0;
	while (index++ < lexer_head->length)
	{
		if (index)
		{
			return (free_lexer(lexer_head));
		}
		lexer = lexer->next;
	}
	return (free_lexer(lexer_head), split_command);
}
