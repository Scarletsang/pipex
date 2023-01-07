/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:58:41 by htsang            #+#    #+#             */
/*   Updated: 2023/01/07 16:00:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_HEREDOC_H
# define PIPEX_HEREDOC_H

# include "../processes/pipex_processes.h"

int				heredoc_main(int argc, const char **argv, char *const *envp);

int				is_heredoc(const char *str);

char			*get_next_line(int fd);

int				is_delimiter_with_new_line(char *str, const char *delimiter);

#endif