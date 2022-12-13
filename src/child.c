/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:14:01 by htsang            #+#    #+#             */
/*   Updated: 2022/12/13 15:53:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	exec_cmd_from_file(const char *cmd, const char *infile, int pipe[2])
{
	int file_fd;

	file_fd = open(infile, O_RDONLY);
	close(pipe[0]);
	dup2(file_fd, STDIN_FILENO);
	dup2(pipe[1], STDOUT_FILENO);
	// TODO: execve();
}

void	exec_cmd_to_cmd(const char *cmd, int pipe1[2], int pipe2[2])
{
	close(pipe1[1]);
	close(pipe2[0]);
	dup2(pipe1[0], STDIN_FILENO);
	dup2(pipe2[1], STDOUT_FILENO);
	// TODO: execve();
}

void	exec_cmd_to_file(const char *cmd, int pipe[2], const char *outfile)
{
	int	file_fd;

	file_fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC);
	close(pipe[1]);
	dup2(pipe[0], STDIN_FILENO);
	dup2(file_fd, STDOUT_FILENO);
	// TODO: execve();
}