/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:24:01 by htsang            #+#    #+#             */
/*   Updated: 2022/12/30 22:47:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_path_expander.h"

size_t	ft_expanded_pathlen(char const *path_envp, \
size_t executable_name_len)
{
	size_t	expand_path_len;

	expand_path_len = 0;
	while (*path_envp && *path_envp != ':')
	{
		expand_path_len++;
		path_envp++;
	}
	return (expand_path_len + 1 + executable_name_len);
}
