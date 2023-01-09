/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_consumer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:17:44 by htsang            #+#    #+#             */
/*   Updated: 2023/01/09 00:27:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lexer.h"

/**
 * @brief Discard spaces without consuming them.
 * @param command_args memory address of a command string input by the user
 */
void	ignore_spaces(char const **command_args)
{
	while (**command_args && ft_isspace(**command_args))
	{
		(*command_args)++;
	}
}

/**
 * @brief Consume a single character
 * @param command_args memory address of a command string input by the user
 * @param lexer a lexer node
 */
void	consume_char(char const **command_args, t_pipex_lexer_node *lexer)
{
	(lexer->length)++;
	(*command_args)++;
}

/**
 * @brief Peeks behind an escape character ffrom the beginning of a string,
 * and returns the memory address after the escape character.
 * @param str the string to find the escape character from
 * @return the memory address behind the escape character, or NULL if
 * escape character is not found.
 */
const char	*peek_behind_escape_char(const char *str)
{
	if (*str == '\\')
	{
		return (str + 1);
	}
	return (NULL);
}

/**
 * @brief Peeks behind the match string from the beginning of a string,
 * and returns the memory address of the character after the match.
 * @param match the match string to be matched
 * @param str the string to find the match string from
 * @return the memory address behind the matching character, or if the
 * match string is not found, returns NULL.
 */
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
