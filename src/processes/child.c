/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:38:45 by htsang            #+#    #+#             */
/*   Updated: 2022/12/16 18:46:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "pipex_processes.h"

static void	close_pipe(int pipe[2])
{
	close(pipe[0]);
	close(pipe[1]);
}

int	infile_to_command(int write_pipe[2], t_pipex_parser *parser)
{
	int file_fd;

	file_fd = open_file_from_parser(O_RDONLY, parser);
	dup2(file_fd, STDIN_FILENO);
	dup2(write_pipe[1], STDOUT_FILENO);
	close(file_fd);
	close_pipe(write_pipe);
	return (execve_command_from_parser(parser));
}

int	command_to_command(int read_pipe[2], int write_pipe[2], t_pipex_parser *parser)
{
	dup2(read_pipe[0], STDIN_FILENO);
	dup2(write_pipe[1], STDOUT_FILENO);
	close_pipe(read_pipe);
	close_pipe(write_pipe);
	return (execve_command_from_parser(parser));
}

int	command_to_outfile(int read_pipe[2], t_pipex_parser *parser)
{
	int	file_fd;

	file_fd = open_file_from_parser(O_CREAT | O_WRONLY | O_TRUNC, parser);
	dup2(read_pipe[0], STDIN_FILENO);
	dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
	close_pipe(read_pipe);
	return (execve_command_from_parser(parser));
}
