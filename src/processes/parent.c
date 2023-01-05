/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:43:52 by htsang            #+#    #+#             */
/*   Updated: 2023/01/04 22:17:16 by htsang           ###   ########.fr       */
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
	wait(NULL);
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
	wait(NULL);
	switch_pipe(states);
	parser_walk_forward(get_parser(states));
}

int	fork_command_to_outfile(t_pipex_states *states)
{
	int	wstatus;

	if (safe_fork(states) == 0)
	{
		run_command_to_outfile(states);
		exit(127);
	}
	close_pipe(get_last_pipe(states));
	wait(&wstatus);
	return (WEXITSTATUS(wstatus));
}
