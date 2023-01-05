/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:44:21 by htsang            #+#    #+#             */
/*   Updated: 2023/01/05 23:49:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_states.h"

int	handle_program_error(t_pipex_states *states)
{
	print_program_error(states->program_name, NULL);
	free_parser_data(get_parser(states));
	return (1);
}

int	handle_child_error(t_pipex_states *states)
{
	t_pipex_parser	*parser;

	parser = get_parser(states);
	print_child_error(states->program_name, \
		get_parser_executable(parser), NULL);
	free_parser_data(parser);
	return (1);
}

int	handle_file_permission_error(t_pipex_states *states)
{
	print_file_permission_error(states);
	free_parser_data(get_parser(states));
	return (1);
}

int	handle_command_not_found_error(char *executable, \
t_pipex_states *states)
{
	print_command_not_found_error(executable, states);
	if (get_parser_executable(get_parser(states)) != executable)
	{
		free(executable);
	}
	free_parser_data(get_parser(states));
	return (1);
}

int	crash_when_minus_1(int func_return_value, t_pipex_states *states)
{
	if (func_return_value == -1)
	{
		handle_program_error(states);
		free(states);
		exit(EXIT_FAILURE);
	}
	return (func_return_value);
}
