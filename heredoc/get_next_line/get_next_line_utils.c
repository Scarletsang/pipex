/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:57:25 by htsang            #+#    #+#             */
/*   Updated: 2022/11/21 19:53:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @param str: a NULL-terminated string
 * @return the length of the given string
 */
static size_t	ft_strlen(const char *str)
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

/**
 * @brief A non traditional strncpy, where only one 0 will be
 * written after the copying n chars from a source string.
 * 
 * @param dest: the destination string to write to
 * @param src: the source string to copy from
 * @param n: the maximum length of characters to copt from src
 * @return the destination string
 */
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * @brief Append a string of length to the end of the dest string.
 * Dest can be null, then it will create a copy of a source string
 * with a given maximum length.
 * 
 * @param dest: the dest NULL-terminated string to append to,
 * this memory address will be freed.
 * @param src: the NULL-terminated string to be appended.
 * @param len: the maximum length of characters to append from src
 * @return a new dest string after concatenation.
 */
char	*ft_strljoin(char *dest, char const *src, size_t len)
{
	size_t	s1_len;
	char	*new_str;

	if (dest)
	{
		s1_len = ft_strlen(dest);
		new_str = (char *) malloc(s1_len + len + 1);
		if (!new_str)
			return (free(dest), NULL);
		ft_strncpy(new_str, dest, s1_len);
		ft_strncpy(new_str + s1_len, src, len);
		free(dest);
	}
	else
	{
		new_str = (char *) malloc(len + 1);
		if (!new_str)
			return (NULL);
		ft_strncpy(new_str, src, len);
	}
	return (new_str);
}

/**
 * @brief Duplicates a string to a new memory address.
 * 
 * @param str: a NULL-terminated stirng
 * @return the new string after duplication from the given string
 */
char	*ft_strdup(const char *str)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(str);
	copy = (char *) malloc(len + 1);
	if (!copy)
	{
		return (NULL);
	}
	ft_strncpy(copy, str, len + 1);
	return (copy);
}
