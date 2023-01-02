/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:14:17 by htsang            #+#    #+#             */
/*   Updated: 2023/01/02 18:48:44 by htsang           ###   ########.fr       */
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
		perror(NULL);
	}
	return (file_fd);
}

int	safe_execve_from_states(t_pipex_states *states)
{
	t_pipex_parser	*parser;

	parser = get_parser(states);
	expand_executable_path(
		parse_command(parser));
	execve(get_parser_executable(parser), \
			get_parser_command(parser), parser->envp);
	handle_command_not_found_error(states);
	return (1);
}
