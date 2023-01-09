/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:14:17 by htsang            #+#    #+#             */
/*   Updated: 2023/01/09 22:42:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_processes.h"

int	safe_pipe(int fds[2], t_pipex_states *states)
{
	return (crash_when_minus_1(pipe(fds), states));
}

int	safe_fork(t_pipex_states *states)
{
	return (crash_when_minus_1(fork(), states));
}

int	safe_open_from_states(int permission, t_pipex_states *states)
{
	int	file_fd;

	file_fd = open(
			get_parser_data(
				parse_filename(
					get_parser(states))), permission, 0644);
	if (file_fd == -1)
	{
		print_no_file_error(states);
	}
	return (file_fd);
}

t_pipex_exit_code	safe_execve_from_states(t_pipex_states *states)
{
	t_pipex_parser	*parser;
	char			*unexpanded_executable;

	parser = get_parser(states);
	if (parsing_failed(parse_command(parser)))
	{
		return (handle_program_error(states));
	}
	unexpanded_executable = get_parser_executable(parser);
	if (!is_a_path(unexpanded_executable))
	{
		if (!expand_executable_path(parser))
		{
			return (handle_command_not_found_error(unexpanded_executable, \
			states));
		}
	}
	execve(get_parser_executable(parser), \
			get_parser_command(parser), parser->envp);
	if (access(get_parser_executable(parser), X_OK) == -1)
	{
		return (handle_file_permission_error(states));
	}
	return (handle_command_not_found_error(unexpanded_executable, states));
}
