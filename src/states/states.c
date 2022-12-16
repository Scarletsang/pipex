/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:14:09 by htsang            #+#    #+#             */
/*   Updated: 2022/12/16 19:59:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_states.h"

t_pipex_states	*switch_pipe(t_pipex_states *states)
{
	if (states->write_pipe_index == 0)
	{
		
	}
}

t_pipex_states	*init_states(char const **argv, char *const *envp)
{
	t_pipex_states	*states;

	states = malloc(sizeof(t_pipex_states));
	if (!states)
	{
		return (NULL);
	}
	states->write_pipe_index = 0;
	init_parser(argv, envp, &states->parser);
	return (states);
}
