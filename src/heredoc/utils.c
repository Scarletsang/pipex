/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:25:48 by htsang            #+#    #+#             */
/*   Updated: 2023/01/06 23:43:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_heredoc.h"

/**
** @brief Compare the first different byte found between two strings.
** Comparision stops when a string terminated.
**
** @param s1: 1st string.
** @param s2: 2nd string.
** @return 0 if both strings are identical in value,
** negative numbers if m1 < m2, positive numbers if m1 > m2.
*/
static const char	*consume_matching_str(const char *match, const char *str)
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

int	is_heredoc(const char *str)
{
	const char	*match;

	match = consume_matching_str("here_doc", str);
	if (!match)
	{
		return (0);
	}
	return (*match == 0);
}

int	is_delimiter_with_new_line(char *str, const char *delimiter)
{
	const char	*match;

	match = consume_matching_str(delimiter, str);
	if (!match)
	{
		return (0);
	}
	return (*match == '\n');
}
