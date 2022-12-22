/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:14:09 by htsang            #+#    #+#             */
/*   Updated: 2022/12/22 20:10:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_states.h"

t_pipex_states	*switch_pipe(t_pipex_states *states)
{
	if (states->write_pipe_index == 0)
	{
		states->write_pipe_index = 2;
	}
	else
	{
		states->write_pipe_index = 0;
	}
	return (states);
}

int	*get_write_pipe(t_pipex_states *states)
{
	return (states->pipes + states->write_pipe_index);
}

int	*get_read_pipe(t_pipex_states *states)
{
	if (states->write_pipe_index == 0)
	{
		return (states->pipes + 2);
	}
	return (states->pipes);
}

t_pipex_states	*get_parser(t_pipex_states *states)
{
	return (&(states->parser));
}

t_pipex_states	*init_states(char const **argv, char *const *envp)
{
	t_pipex_states	*states;

	states = malloc(sizeof(t_pipex_states));
	if (!states)
	{
		perror(errno);
		return (NULL);
	}
	states->write_pipe_index = 0;
	init_parser(argv, envp, &states->parser);
	return (states);
}
