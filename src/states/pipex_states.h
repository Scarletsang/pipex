/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_states.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:55:29 by htsang            #+#    #+#             */
/*   Updated: 2022/12/24 18:55:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STATES_H
# define PIPEX_STATES_H

# include <string.h>
# include <errno.h>
# include "../parser/pipex_parser.h"

typedef struct s_pipex_states
{
	int				pipes[4];
	int				write_pipe_index;
	t_pipex_parser	parser;
}				t_pipex_states;

t_pipex_states	*switch_pipe(t_pipex_states *states);

int				*get_write_pipe(t_pipex_states *states);

int				*get_read_pipe(t_pipex_states *states);

t_pipex_parser	*get_parser(t_pipex_states *states);

t_pipex_states	*init_states(char const **argv, char *const *envp);

//////////////////////////////////
////      crash on error     /////
//////////////////////////////////

void			handle_error(t_pipex_states *states);

int				crash_when_minus_1(int func_return_value, t_pipex_states *states);

char			*crash_invalid_str(char *func_return_value, \
t_pipex_states *states);

int				crash_when_false(int func_return_value, t_pipex_states *states);

#endif