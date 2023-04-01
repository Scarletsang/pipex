/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:14:17 by htsang            #+#    #+#             */
/*   Updated: 2023/04/01 21:45:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_processes.h"
#include <unistd.h>

extern char	**environ;

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
	char			*executable_path;

	parser = get_parser(states);
	if (parsing_failed(parse_command(parser)))
	{
		return (handle_program_error(states));
	}
	executable_path = get_parser_command(parser)[0];
	if (!is_a_path(executable_path))
	{
		executable_path = expand_executable_path(parser);
		if (!executable_path)
			return (handle_command_not_found_error(\
				get_parser_command(parser)[0], states));
	}
	if (access(executable_path, X_OK) == -1)
	{
		return (handle_file_permission_error(states));
	}
	execve(executable_path, get_parser_command(parser), environ);
	return (handle_command_not_found_error(executable_path, states));
}
