/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:21:52 by htsang            #+#    #+#             */
/*   Updated: 2023/01/04 23:42:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *) malloc(s1_len + s2_len + 1);
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, s1);
	ft_strcpy(new_str + s1_len, s2);
	return (new_str);
}

int	main(int argc, char **argv)
{
	if (argc < 0)
	{
		return (1);
	}
	errno = 1;
	perror("-----------------------");
	while (errno <= 102)
	{
		perror(ft_strjoin(argv[0], ": command"));
		errno++;
	}
	exit(127);
}
