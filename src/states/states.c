/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:14:09 by htsang            #+#    #+#             */
/*   Updated: 2022/12/30 18:27:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_states.h"

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

t_pipex_states	*init_states(char const **argv, char *const *envp)
{
	t_pipex_states	*states;

	states = malloc(sizeof(t_pipex_states));
	if (!states)
	{
		perror(strerror(errno));
		return (NULL);
	}
	states->last_pipe_index = 0;
	init_parser(argv, envp, &states->parser);
	return (states);
}
