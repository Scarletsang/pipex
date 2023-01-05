/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_copier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:08:23 by htsang            #+#    #+#             */
/*   Updated: 2023/01/05 14:54:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex_lexer.h"

static const char	*skip_quote(const char *quote, \
const char **command_args)
{
	if (quote && (*quote == '\'' || *quote == '\"'))
	{
		(*command_args)++;
		return (quote);
	}
	return (NULL);
}

static int	skip_escape_char(const char **command_args)
{
	if (**command_args == '\\')
	{
		if ((*command_args)[1])
		{
			(*command_args)++;
			return (0);
		}
	}
	return (1);
}

static int	converter_copier(char **split_command, \
const char **command_args, t_pipex_lexer_node *lexer)
{
	size_t	i;

	*split_command = malloc(lexer->length + 1);
	if (!(*split_command))
	{
		return (1);
	}
	(*split_command)[lexer->length] = 0;
	i = 0;
	while (i < lexer->length)
	{
		skip_escape_char(command_args);
		(*split_command)[i] = **command_args;
		i++;
		(*command_args)++;
	}
	return (0);
}

int	run_converter_copier(char **split_command, \
const char **command_args, t_pipex_lexer_node *lexer)
{
	const char	*quote;

	quote = skip_quote(*command_args, command_args);
	if (converter_copier(split_command, command_args, lexer))
	{
		return (1);
	}
	skip_quote(quote, command_args);
	ignore_spaces(command_args);
	return (0);
}
