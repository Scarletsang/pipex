/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_processes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:39:00 by htsang            #+#    #+#             */
/*   Updated: 2023/01/03 20:29:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PROCESSES_H
# define PIPEX_PROCESSES_H

# include <fcntl.h>
# include <unistd.h>
# include "../states/pipex_states.h"
# include "../path_expander/pipex_path_expander.h"

////////////////////////////////////
////      Parent processes     /////
////////////////////////////////////

void	fork_command_from_infile(t_pipex_states *states);

void	fork_command(t_pipex_states *states);

int		fork_command_to_outfile(t_pipex_states *states);

////////////////////////////////////
////      Child processes      /////
////////////////////////////////////

int		run_command_from_infile(t_pipex_states *states);

int		run_command(t_pipex_states *states);

int		run_command_to_outfile(t_pipex_states *states);

////////////////////////////////////////////////
////      safe execution of functions      /////
////////////////////////////////////////////////

int		safe_pipe(int fds[2], t_pipex_states *states);

int		safe_fork(t_pipex_states *states);

int		safe_open_from_states(int permission, t_pipex_states *states);

int		safe_execve_from_states(t_pipex_states *states);

////////////////////////////////////
////         Utilities         /////
////////////////////////////////////

void	close_pipe(int pipe[2]);

#endif