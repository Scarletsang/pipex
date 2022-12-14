/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:33:13 by htsang            #+#    #+#             */
/*   Updated: 2022/12/14 18:49:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fork_first_cmd(t_cmds *cmds, int outpipe[2])
{
	pid_t	fork_pid;

	pipe_with_eh(outpipe);
	fork_pid = fork();
	if (fork_pid == 0)
	{
		exec_cmd_from_file(cmds);
	}
}