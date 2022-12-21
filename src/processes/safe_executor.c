/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:14:17 by htsang            #+#    #+#             */
/*   Updated: 2022/12/22 00:26:42 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_processes.h"

int	safe_pipe(int fds[2], t_pipex_states *states)
{
	return(crash_when_minus_1(pipe(fds), states));
}

int	safe_fork(t_pipex_states *states)
{
	return (crash_when_minus_1(fork(), states));
}

int	safe_open_from_states(int permission, t_pipex_states *states)
{
	return (open(
				get_parser_data(
					parse_filename(
						get_parser(states))), permission));
}

int	safe_execve_from_states(t_pipex_states *states)
{
	t_pipex_parser	*parser;

	parser = get_parser(states);
	if (parsing_failed(parse_command(parser)))
	{
		return (1);
	}
	execve(((char **) get_parser_data(parser))[0], \
			(char **) get_parser_data(parser), parser->envp);
	return (1);
}
