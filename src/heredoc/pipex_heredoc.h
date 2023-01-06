/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:58:41 by htsang            #+#    #+#             */
/*   Updated: 2023/01/06 23:36:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_HEREDOC_H
# define PIPEX_HEREDOC_H

# include "../processes/pipex_processes.h"

char			*get_next_line(int fd);

t_pipex_parser	*parse_heredoc(t_pipex_parser *parser);

void			fork_command_from_heredoc(t_pipex_states *states);

int				is_heredoc(const char *str);

int				is_delimiter_with_new_line(char *str, const char *delimiter);

#endif