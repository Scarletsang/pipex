/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoted_string_consumer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:08:23 by htsang            #+#    #+#             */
/*   Updated: 2023/01/03 19:12:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lexer.h"

static int	consume_quoted_string_escape_char(char const **command_args, \
t_pipex_lexer_node *lexer)
{
	if (**command_args == '\\')
	{
		consume_char(command_args, lexer);
		if (**command_args)
		{
			consume_char(command_args, lexer);
		}
		return (0);
	}
	return (1);
}

int	consume_quoted_string(char const **command_args, \
t_pipex_lexer_node *lexer)
{
	char	quote;

	if (**command_args != '\'' && **command_args != '\"')
	{
		return (1);
	}
	quote = **command_args;
	consume_char(command_args, lexer);
	while (**command_args && **command_args != quote)
	{
		if (!consume_quoted_string_escape_char(command_args, lexer))
		{
			continue ;
		}
		consume_char(command_args, lexer);
	}
	if (**command_args == quote)
	{
		consume_char(command_args, lexer);
	}
	return (0);
}
