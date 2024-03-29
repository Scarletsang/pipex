/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_processes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:39:00 by htsang            #+#    #+#             */
/*   Updated: 2023/04/01 21:42:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PROCESSES_H
# define PIPEX_PROCESSES_H

# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../states/pipex_states.h"

////////////////////////////////////
////      Parent processes     /////
////////////////////////////////////

void				fork_command_from_infile(t_pipex_states *states);

void				fork_command(t_pipex_states *states);

pid_t				fork_command_to_outfile(int permission, \
t_pipex_states *states);

////////////////////////////////////
////      Child processes      /////
////////////////////////////////////

t_pipex_exit_code	run_command_from_infile(t_pipex_states *states);

t_pipex_exit_code	run_command(t_pipex_states *states);

t_pipex_exit_code	run_command_to_outfile(int permission, \
t_pipex_states *states);

////////////////////////////////////////////////
////      safe execution of functions      /////
////////////////////////////////////////////////

int					safe_pipe(int fds[2], t_pipex_states *states);

int					safe_fork(t_pipex_states *states);

int					safe_open_from_states(int permission, \
t_pipex_states *states);

t_pipex_exit_code	safe_execve_from_states(t_pipex_states *states);

////////////////////////////////////
////         Utilities         /////
////////////////////////////////////

void				close_pipe(int pipe[2]);

int					wait_all_children(pid_t last_child_pid);

#endif