/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:44:10 by htsang            #+#    #+#             */
/*   Updated: 2022/12/14 19:23:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "../parser/parser.h"

int		handle_err(int func_return_value);

char	**ft_split_with_eh(char const *str, char c);

int		pipe_with_eh(int pipefd[2]);

pid_t	fork_with_eh(void);

int		execve_with_eh(const char *pathname, char *const argv[], \
char *const envp[]);

#endif