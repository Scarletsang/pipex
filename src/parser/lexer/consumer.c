/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consumer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:44:45 by htsang            #+#    #+#             */
/*   Updated: 2023/01/03 19:15:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lexer.h"

void	consume_char(char const **command_args, \
t_pipex_lexer_node *lexer)
{
	(lexer->length)++;
	(*command_args)++;
}

void	ignore_spaces(char const **command_args)
{
	while (**command_args && ft_isspace(**command_args))
	{
		(*command_args)++;
	}
}

static int	consume_escape_char(char const **command_args, \
t_pipex_lexer_node *lexer)
{
	if (**command_args == '\\')
	{
		(*command_args)++;
		if (**command_args)
		{
			consume_char(command_args, lexer);
		}
		return (0);
	}
	return (1);
}

/**
 * @brief Consume a single argument from the command arguments.
 * @details 
 * 1. Consume \" or \'
 * 2. Detect  " or  '
 *   2.1 Consume \" or \'
 *   2.2 Detect  " or  ' for ending the string
 * 3. Ignore spaces
 * @param command_args The unparsed command arguments string
 * @param lexer Lexer node
 * @return One lexed command argument
 */
t_pipex_lexer_node	*consume_command_arg(char const **command_args, \
t_pipex_lexer_node *lexer)
{
	while (**command_args && !ft_isspace(**command_args))
	{
		if (!consume_escape_char(command_args, lexer))
		{
			continue ;
		}
		if (!consume_quoted_string(command_args, lexer))
		{
			continue ;
		}
		consume_char(command_args, lexer);
	}
	ignore_spaces(command_args);
	return (lexer);
}
