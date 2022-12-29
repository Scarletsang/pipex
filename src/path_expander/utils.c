/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:24:01 by htsang            #+#    #+#             */
/*   Updated: 2022/12/29 23:53:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_path_expander.h"

/**
** @param str: a NULL-terminated string
** @return the length of the given string
*/
size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

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

/**
** @brief Naive copying from src to dest.
**
** @param dest: the destination memory address to copy to.
** @param src:  a NULL-terminated string to be copied from.
** @return the destination string
*/
char	*ft_strcpy(char *dest, const char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (dest);
}
