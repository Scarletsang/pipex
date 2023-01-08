/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:25:48 by htsang            #+#    #+#             */
/*   Updated: 2023/01/08 22:30:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_heredoc.h"

int	is_heredoc(const char *str)
{
	const char	*match;

	match = peek_behind_matching_str("here_doc", str);
	if (!match)
	{
		return (0);
	}
	return (*match == 0);
}

int	is_delimiter_with_new_line(char *str, const char *delimiter)
{
	const char	*match;

	match = peek_behind_matching_str(delimiter, str);
	if (!match)
	{
		return (0);
	}
	return (*match == '\n');
}
