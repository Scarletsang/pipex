/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:43:52 by htsang            #+#    #+#             */
/*   Updated: 2022/12/22 20:17:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_processes.h"

void	fork_command_from_infile(t_pipex_states *states)
{
	safe_pipe(get_write_pipe(states), states);
	if (safe_fork(states) == 0)
	{
		run_command_from_infile(states);
		handle_error(states);
		exit(EXIT_FAILURE);
	}
	wait(NULL);
	parser_walk_forward(
		parser_walk_forward(get_parser(states)));
}

void	fork_command(t_pipex_states *states)
{
	safe_pipe(get_read_pipe(states), states);
	if (safe_fork(states) == 0)
	{
		run_command(states);
		handle_error(states);
		exit(EXIT_FAILURE);
	}
	close_pipe(get_write_pipe(states));
	wait(NULL);
	switch_pipe(states);
	parser_walk_forward(get_parser(states));
}

void	fork_command_to_outfile(t_pipex_states *states)
{
	if (safe_fork(states) == 0)
	{
		run_command_to_outfile(states);
		handle_error(states);
		exit(EXIT_FAILURE);
	}
	close_pipe(get_write_pipe(states));
	wait(NULL);
	parser_walk_forward(
		parser_walk_forward(get_parser(states)));
}
