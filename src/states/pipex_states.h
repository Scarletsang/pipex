/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_states.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:55:29 by htsang            #+#    #+#             */
/*   Updated: 2022/12/16 19:40:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STATES_H
# define PIPEX_STATES_H

# include "../parser/pipex_parser.h"

typedef struct s_pipex_states
{
	int				pipes[4];
	int				write_pipe_index;
	t_pipex_parser	parser;
}				t_pipex_states;

#endif