/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:39:28 by htsang            #+#    #+#             */
/*   Updated: 2022/12/14 19:36:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "error/error.h"

typedef struct s_cmds
{
	char *const	*envp;
	char 		**argv;
}				t_cmds;

int	exec_cmd_from_file(t_cmds *cmds, int write_pipe[2]);

int	exec_cmd_to_cmd(t_cmds *cmds, int read_pipe[2], int write_pipe[2]);

int	exec_cmd_to_file(t_cmds *cmds, int read_pipe[2]);

char	**get_cmd(t_cmds *iterator);

t_cmds	*init_cmds(char const **argv, char *const *envp);

void	close_pipe_with_eh(t_cmds *cmds, int pipe[2]);

#endif