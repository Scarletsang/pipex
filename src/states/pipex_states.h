/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_states.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:55:29 by htsang            #+#    #+#             */
/*   Updated: 2023/01/08 18:23:29 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STATES_H
# define PIPEX_STATES_H

# include "../parser/pipex_parser.h"

typedef struct s_pipex_states
{
	const char		*program_name;
	int				pipes[4];
	int				last_pipe_index;
	t_pipex_parser	parser;
}				t_pipex_states;

int					*get_last_pipe(t_pipex_states *states);

int					*get_next_pipe(t_pipex_states *states);

t_pipex_parser		*get_parser(t_pipex_states *states);

t_pipex_states		*init_states(char const **argv, char *const *envp);

//////////////////////////////////
////      crash on error     /////
//////////////////////////////////

typedef enum e_pipex_exit_code
{
	PROGRAM_SUCCESS = EXIT_SUCCESS,
	PROGRAM_FAILURE = EXIT_FAILURE,
	NO_PERMISSION_FAILURE = 126,
	COMMAND_NOT_FOUND_FAILURE = 127
}				t_pipex_exit_code;

t_pipex_exit_code	handle_program_error(t_pipex_states *states);

t_pipex_exit_code	handle_child_error(t_pipex_states *states);

t_pipex_exit_code	handle_file_permission_error(t_pipex_states *states);

t_pipex_exit_code	handle_command_not_found_error(char *executable, \
t_pipex_states *states);

int					crash_when_minus_1(int func_return_value, \
t_pipex_states *states);

//////////////////////////////////
////      Error printer      /////
//////////////////////////////////

void				print_program_error(const char *program_name, \
const char *error_msg);

void				print_child_error(const char *program_name, \
const char *executable, const char *error_msg);

void				print_command_not_found_error(char *executable, \
t_pipex_states *states);

void				print_no_file_error(t_pipex_states *states);

void				print_file_permission_error(t_pipex_states *states);

//////////////////////////////////
////        Utilities        /////
//////////////////////////////////

int					is_a_path(char *command);

const char			*get_program_name(char const *argv);

#endif