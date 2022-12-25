/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consumer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:44:45 by htsang            #+#    #+#             */
/*   Updated: 2022/12/26 00:19:27 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lexer.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
		c == '\v' || c == '\f' || c == '\r');
}

static void	consume_escape_char(char const **command_args, \
t_pipex_lexer_node *lexer)
{
	if (**command_args == '\\')
	{
		(lexer->length)++;
		(*command_args)++;
		if (**command_args)
		{
			(lexer->length)++;
			(*command_args)++;
		}
	}
}

static void	consume_quoted_string(char const **command_args, \
t_pipex_lexer_node *lexer)
{
	char	quote;

	if (**command_args != '\'' && **command_args != '\"')
	{
		return ;
	}
	quote = **command_args;
	(lexer->length)++;
	(*command_args)++;
	while (**command_args && **command_args != quote)
	{
		consume_escape_char(command_args, lexer);
		(lexer->length)++;
		(*command_args)++;
	}
	if (**command_args == quote)
	{
		(lexer->length)++;
	}
}

void	ignore_spaces(char const **command_args)
{
	while (**command_args && ft_isspace(**command_args))
	{
		(*command_args)++;
	}
}

/**
 * @brief 
 * @details 
	// Consume \" or \'
	// Detect  " or  '
		// Consume \" or \'
		// Detect  " or  ' for ending the string
	// Ignore spaces
 * @param str 
 * @param lexer Lexer node
 * @return 
 */
t_pipex_lexer_node	*consume_command_arg(char const *command_args, \
t_pipex_lexer_node *lexer)
{
	if (!lexer)
	{
		return (NULL);
	}
	while (*command_args && !ft_isspace(*command_args))
	{
		consume_escape_char(&command_args, lexer);
		consume_quoted_string(&command_args, lexer);
	}
	ignore_spaces(command_args);
	return (lexer);
}
