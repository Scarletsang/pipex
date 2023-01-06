/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:43:52 by htsang            #+#    #+#             */
/*   Updated: 2023/01/07 00:12:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_processes.h"

void	fork_command_from_infile(t_pipex_states *states)
{
	safe_pipe(get_next_pipe(states), states);
	if (safe_fork(states) == 0)
	{
		run_command_from_infile(states);
		exit(127);
	}
	switch_pipe(states);
	parser_walk_forward(
		parser_walk_forward(get_parser(states)));
}

void	fork_command(t_pipex_states *states)
{
	safe_pipe(get_next_pipe(states), states);
	if (safe_fork(states) == 0)
	{
		run_command(states);
		exit(127);
	}
	close_pipe(get_last_pipe(states));
	switch_pipe(states);
	parser_walk_forward(get_parser(states));
}

int	fork_command_to_outfile(t_pipex_states *states)
{
	int		wstatus;
	pid_t	pid;

	pid = safe_fork(states);
	if (pid == 0)
	{
		run_command_to_outfile(states);
		exit(127);
	}
	close_pipe(get_last_pipe(states));
	free(states);
	waitpid(pid, &wstatus, 0);
	return (WEXITSTATUS(wstatus));
}
