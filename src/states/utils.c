/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 00:23:03 by htsang            #+#    #+#             */
/*   Updated: 2023/01/06 00:36:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_states.h"

int	is_a_path(char *command)
{
	while (*command)
	{
		if (*command == '/')
		{
			return (1);
		}
		if (get_escape_char((const char *) command))
		{
			command++;
		}
		command++;
	}
	return (0);
}

const char	*get_program_name(const char *argv)
{
	const char	*original;
	const char	*program_name;

	original = argv;
	program_name = NULL;
	while (*argv)
	{
		if (*argv == '/')
		{
			program_name = argv + 1;
		}
		if (get_escape_char(argv))
		{
			argv++;
		}
		argv++;
	}
	if (program_name)
	{
		return (program_name);
	}
	return (original);
}
