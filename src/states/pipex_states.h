/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_states.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:55:29 by htsang            #+#    #+#             */
/*   Updated: 2023/01/05 01:27:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STATES_H
# define PIPEX_STATES_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include "../parser/pipex_parser.h"

typedef struct s_pipex_states
{
	const char		*program_name;
	int				pipes[4];
	int				last_pipe_index;
	t_pipex_parser	parser;
}				t_pipex_states;

int				*get_last_pipe(t_pipex_states *states);

int				*get_next_pipe(t_pipex_states *states);

t_pipex_parser	*get_parser(t_pipex_states *states);

t_pipex_states	*init_states(char const **argv, char *const *envp);

//////////////////////////////////
////      crash on error     /////
//////////////////////////////////

void			handle_error(t_pipex_states *states);

void			handle_command_not_found_error(char *executable, \
t_pipex_states *states);

int				crash_when_minus_1(int func_return_value, \
t_pipex_states *states);

//////////////////////////////////
////      Error printer      /////
//////////////////////////////////

void			print_not_found_error(char *executable, \
t_pipex_states *states);

void			print_no_file_error(t_pipex_states *states);

#endif