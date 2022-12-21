/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:43:52 by htsang            #+#    #+#             */
/*   Updated: 2022/12/22 00:19:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_processes.h"

void	in(t_pipex_states *states)
{
	safe_pipe(get_write_pipe(states), states);
	if (safe_fork(states) == 0)
	{
		run_command_from_infile(states);
		handle_error(states);
		exit(EXIT_FAILURE);
	}
	wait(NULL);
}

void	nomral(t_pipex_states *states)
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
}

void	out(t_pipex_states *states)
{
	if (safe_fork(states) == 0)
	{
		run_command_to_outfile(states);
		handle_error(states);
		exit(EXIT_FAILURE);
	}
	close_pipe(get_write_pipe(states));
	wait(NULL);
}
