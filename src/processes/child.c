/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:38:45 by htsang            #+#    #+#             */
/*   Updated: 2022/12/24 19:30:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_processes.h"

int	run_command_from_infile(t_pipex_states *states)
{
	int	infile_fd;
	int	*write_pipe;

	infile_fd = safe_open_from_states(O_RDONLY, states);
	if (infile_fd == -1)
	{
		strerror(errno);
		close(STDIN_FILENO);
	}
	else
	{
		dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
	}
	write_pipe = get_write_pipe(states);
	dup2(write_pipe[1], STDOUT_FILENO);
	close_pipe(write_pipe);
	parser_walk_forward(get_parser(states));
	return (safe_execve_from_states(states));
}

int	run_command(t_pipex_states *states)
{
	int	*read_pipe;
	int	*write_pipe;

	read_pipe = get_read_pipe(states);
	write_pipe = get_write_pipe(states);
	dup2(read_pipe[0], STDIN_FILENO);
	dup2(write_pipe[1], STDOUT_FILENO);
	close_pipe(read_pipe);
	close_pipe(write_pipe);
	return (safe_execve_from_states(states));
}

int	run_command_to_outfile(t_pipex_states *states)
{
	int	*read_pipe;
	int	outfile_fd;

	parser_walk_forward(get_parser(states));
	outfile_fd = safe_open_from_states(O_RDONLY, states);
	read_pipe = get_read_pipe(states);
	if (outfile_fd == -1)
	{
		close_pipe(read_pipe);
		return (-1);
	}
	dup2(outfile_fd, STDOUT_FILENO);
	dup2(read_pipe[0], STDIN_FILENO);
	close(outfile_fd);
	close_pipe(read_pipe);
	parser_walk_backward(get_parser(states));
	return (safe_execve_from_states(states));
}
