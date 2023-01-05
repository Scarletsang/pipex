/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:44:21 by htsang            #+#    #+#             */
/*   Updated: 2023/01/05 01:49:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_states.h"

void	handle_error(t_pipex_states *states)
{
	perror(NULL);
	free_parser_data(get_parser(states));
}

void	handle_command_not_found_error(char *executable, \
t_pipex_states *states)
{
	print_not_found_error(executable, states);
	if (get_parser_executable(get_parser(states)) != executable)
	{
		free(executable);
	}
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
