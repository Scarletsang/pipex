/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path_expander.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:16:38 by htsang            #+#    #+#             */
/*   Updated: 2022/12/28 23:49:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PATH_EXPANDER_H
# define PIPEX_PATH_EXPANDER_H

# include "../parser/pipex_parser.h"

t_pipex_parser	*expand_executable_path(t_pipex_parser *parser);

#endif