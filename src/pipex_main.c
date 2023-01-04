/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:33:13 by htsang            #+#    #+#             */
/*   Updated: 2023/01/03 20:51:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes/pipex_processes.h"

int	main(int argc, const char **argv, char *const *envp)
{
	t_pipex_states	*states;

	if (argc < 5)
	{
		return (EXIT_FAILURE);
	}
	argv++;
	states = init_states(argv, envp);
	if (!states)
	{
		return (EXIT_FAILURE);
	}
	fork_command_from_infile(states);
	while (!check_next_command_is_end(get_parser(states)))
	{
		fork_command(states);
	}
	return (fork_command_to_outfile(states));
}
