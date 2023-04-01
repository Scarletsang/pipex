/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:43:52 by htsang            #+#    #+#             */
/*   Updated: 2023/04/01 20:18:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_processes.h"

void	fork_command_from_infile(t_pipex_states *states)
{
	t_pipex_exit_code	exit_code;

	safe_pipe(get_next_pipe(states), states);
	if (safe_fork(states) == 0)
	{
		exit_code = run_command_from_infile(states);
		exit(exit_code);
	}
	switch_pipe(states);
	parser_walk_forward(
		parser_walk_forward(get_parser(states)));
}

void	fork_command(t_pipex_states *states)
{
	t_pipex_exit_code	exit_code;

	safe_pipe(get_next_pipe(states), states);
	if (safe_fork(states) == 0)
	{
		exit_code = run_command(states);
		exit(exit_code);
	}
	close_pipe(get_last_pipe(states));
	switch_pipe(states);
	parser_walk_forward(get_parser(states));
}

pid_t	fork_command_to_outfile(int permission, t_pipex_states *states)
{
	t_pipex_exit_code	exit_code;
	pid_t				pid;

	pid = safe_fork(states);
	if (pid == 0)
	{
		exit_code = run_command_to_outfile(permission, states);
		exit(exit_code);
	}
	close_pipe(get_last_pipe(states));
	return (pid);
}
