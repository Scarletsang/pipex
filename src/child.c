/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:14:01 by htsang            #+#    #+#             */
/*   Updated: 2022/12/14 18:47:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "pipex.h"

static int	execve_from_cmds(t_cmds *cmds)
{
	char	**cmd;

	cmd = get_cmd(cmds);
	if (cmd)
	{
		execve_with_eh(cmd[0], cmd, cmds->envp);
	}
	free(cmd);
	return (-1);
}

int	exec_cmd_from_file(t_cmds *cmds, int write_pipe[2])
{
	int file_fd;

	file_fd = open_with_eh((cmds->argv)[0], O_RDONLY);
	dup2(file_fd, STDIN_FILENO);
	dup2(write_pipe[1], STDOUT_FILENO);
	close_with_eh(file_fd);
	close_pipe_with_eh(cmds, write_pipe);
	return (execve_from_cmds(cmds));
}

int	exec_cmd_to_cmd(t_cmds *cmds, int read_pipe[2], int write_pipe[2])
{
	dup2(read_pipe[0], STDIN_FILENO);
	dup2(write_pipe[1], STDOUT_FILENO);
	close_pipe_with_eh(cmds, read_pipe);
	close_pipe_with_eh(cmds, write_pipe);
	return (execve_from_cmds(cmds));
}

int	exec_cmd_to_file(t_cmds *cmds, int read_pipe[2])
{
	int	file_fd;

	file_fd = open_with_eh((cmds->argv)[0], O_CREAT | O_WRONLY | O_TRUNC);
	dup2(read_pipe[0], STDIN_FILENO);
	dup2(file_fd, STDOUT_FILENO);
	close_with_eh(file_fd);
	close_pipe_with_eh(cmds, read_pipe);
	return (execve_from_cmds(cmds));
}
