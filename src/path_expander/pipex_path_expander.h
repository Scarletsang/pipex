/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path_expander.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:16:38 by htsang            #+#    #+#             */
/*   Updated: 2023/01/02 18:32:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PATH_EXPANDER_H
# define PIPEX_PATH_EXPANDER_H

# include "../parser/pipex_parser.h"

t_pipex_parser	*expand_executable_path(t_pipex_parser *parser);

size_t			ft_strlen(const char *str);

size_t			ft_expanded_pathlen(char const *path_envp, \
size_t executable_name_len);

#endif