/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:44:21 by htsang            #+#    #+#             */
/*   Updated: 2022/12/30 23:15:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pipex_states.h"

void	handle_error(t_pipex_states *states)
{
	perror(NULL);
	free_parser_data(get_parser(states));
}

void	handle_command_not_found_error(t_pipex_states *states)
{
	char	*executable_name;

	executable_name = get_parser_executable(get_parser(states));
	write(STDERR_FILENO, "command not found: ", 19);
	write(STDERR_FILENO, executable_name, ft_strlen(executable_name));
	write(STDERR_FILENO, "\n", 1);
	free_parser_data(get_parser(states));
}

int	crash_when_minus_1(int func_return_value, t_pipex_states *states)
{
	if (func_return_value == -1)
	{
		handle_error(states);
		free(states);
		exit(EXIT_FAILURE);
	}
	return (func_return_value);
}

char	*crash_invalid_str(char *func_return_value, t_pipex_states *states)
{
	if (func_return_value == NULL)
	{
		handle_error(states);
		free(states);
		exit(EXIT_FAILURE);
	}
	return (func_return_value);
}

int	crash_when_false(int func_return_value, t_pipex_states *states)
{
	if (func_return_value == 0)
	{
		handle_error(states);
		free(states);
		exit(EXIT_FAILURE);
	}
	return (func_return_value);
}
