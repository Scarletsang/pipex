/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_consumer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:17:44 by htsang            #+#    #+#             */
/*   Updated: 2023/01/08 22:31:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lexer.h"

void	ignore_spaces(char const **command_args)
{
	while (**command_args && ft_isspace(**command_args))
	{
		(*command_args)++;
	}
}

void	consume_char(char const **command_args, t_pipex_lexer_node *lexer)
{
	(lexer->length)++;
	(*command_args)++;
}

const char	*peek_behind_escape_char(const char *str)
{
	if (*str == '\\')
	{
		return (str + 1);
	}
	return (NULL);
}

const char	*peek_behind_matching_str(const char *match, const char *str)
{
	while (*match && *str && *match == *str)
	{
		match++;
		str++;
	}
	if (*match)
	{
		return (NULL);
	}
	return (str);
}
