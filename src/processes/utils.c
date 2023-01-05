/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:08:59 by htsang            #+#    #+#             */
/*   Updated: 2023/01/05 00:54:04 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_processes.h"

void	close_pipe(int pipe[2])
{
	close(pipe[0]);
	close(pipe[1]);
}

t_pipex_states	*switch_pipe(t_pipex_states *states)
{
	if (states->last_pipe_index == 0)
	{
		states->last_pipe_index = 2;
	}
	else
	{
		states->last_pipe_index = 0;
	}
	return (states);
}
