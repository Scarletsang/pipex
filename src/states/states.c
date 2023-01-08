/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:14:09 by htsang            #+#    #+#             */
/*   Updated: 2023/01/08 19:03:39 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_states.h"

int	*get_last_pipe(t_pipex_states *states)
{
	return (states->pipes + states->last_pipe_index);
}

int	*get_next_pipe(t_pipex_states *states)
{
	if (states->last_pipe_index == 0)
	{
		return (states->pipes + 2);
	}
	return (states->pipes);
}

t_pipex_parser	*get_parser(t_pipex_states *states)
{
	return (&(states->parser));
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

t_pipex_states	*init_states(char const **argv, char *const *envp)
{
	t_pipex_states	*states;
	const char		*program_name;

	program_name = get_program_name(*argv);
	states = malloc(sizeof(t_pipex_states));
	if (!states)
	{
		print_program_error(program_name, NULL);
		return (NULL);
	}
	states->last_pipe_index = 0;
	states->program_name = program_name;
	argv++;
	init_parser(argv, envp, &states->parser);
	return (states);
}
