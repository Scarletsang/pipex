/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:38:45 by htsang            #+#    #+#             */
/*   Updated: 2022/12/30 18:27:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_processes.h"

int	run_command_from_infile(t_pipex_states *states)
{
	int	infile_fd;
	int	*next_pipe;

	infile_fd = safe_open_from_states(O_RDONLY, states);
	if (infile_fd == -1)
	{
		perror(strerror(errno));
		close(STDIN_FILENO);
	}
	else
	{
		dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
	}
	next_pipe = get_next_pipe(states);
	dup2(next_pipe[1], STDOUT_FILENO);
	close_pipe(next_pipe);
	parser_walk_forward(get_parser(states));
	return (safe_execve_from_states(states));
}

int	run_command(t_pipex_states *states)
{
	int	*last_pipe;
	int	*next_pipe;

	last_pipe = get_next_pipe(states);
	next_pipe = get_last_pipe(states);
	dup2(last_pipe[0], STDIN_FILENO);
	dup2(next_pipe[1], STDOUT_FILENO);
	close_pipe(last_pipe);
	close_pipe(next_pipe);
	return (safe_execve_from_states(states));
}

int	run_command_to_outfile(t_pipex_states *states)
{
	int	*last_pipe;
	int	outfile_fd;

	parser_walk_forward(get_parser(states));
	outfile_fd = safe_open_from_states(O_TRUNC | O_CREAT | O_RDWR, states);
	last_pipe = get_last_pipe(states);
	if (outfile_fd == -1)
	{
		close_pipe(last_pipe);
		return (-1);
	}
	dup2(outfile_fd, STDOUT_FILENO);
	dup2(last_pipe[0], STDIN_FILENO);
	close(outfile_fd);
	close_pipe(last_pipe);
	parser_walk_backward(get_parser(states));
	return (safe_execve_from_states(states));
}
