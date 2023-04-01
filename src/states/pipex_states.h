/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_states.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:55:29 by htsang            #+#    #+#             */
/*   Updated: 2023/04/01 19:30:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STATES_H
# define PIPEX_STATES_H

# include "../parser/pipex_parser.h"

/////////////////////////////////////
////      The state object      /////
/////////////////////////////////////

/**
 * @brief A singleton object storing all states needed for
 * the whole pipex program.
 * 
 * @details The program holds two pipes (4 file descriptors) at
 * maximum to pipe data between the commands. A pipe is created
 * whenever there is a next command to pipe to. The oldest pipe
 * is closed when a new pipe is created. From the perspective of
 * the command, last pipe is the pipe to read from, and next pipe
 * is the pipe to write to. However, in the next command, the
 * previous 'next pipe' has became the 'last pipe' for this
 * command to read from. The 'last_pipe_index' field is used to
 * keep track of this perspective. The functions 'get_last_pipe()',
 * 'get_next_pipe()' and 'switch_pipe()' provides an interface to
 * get the needed pipe, and switching perspectives.
 * 
 */
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

t_pipex_states		*switch_pipe(t_pipex_states *states);

t_pipex_states		*init_states(char const **argv, \
t_pipex_states *states);

//////////////////////////////////
////      Error handler      /////
//////////////////////////////////

/**
 * @brief Each error handler do 3 things:
 * 1. Calls the corresponding error printer to print error messages.
 * 2. Free the state object, and other varaibles (if any).
 * 3. Returns the correct exit code representing the error.
*/

/**
 * @brief Enum for different possible exit codes for pipex
 */
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