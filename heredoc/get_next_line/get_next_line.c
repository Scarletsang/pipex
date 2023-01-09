/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:09:04 by htsang            #+#    #+#             */
/*   Updated: 2022/11/20 21:52:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	find_line_end(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == '\n')
		{
			return (len + 1);
		}
		len++;
	}
	return (0);
}

static char	*free_all(char *buff, char *current, char leftover[BUFFER_SIZE])
{
	leftover[0] = 0;
	if (buff)
	{
		free(buff);
	}
	if (current)
	{
		free(current);
	}
	return (NULL);
}

static char	*main_logic(int fd, char *current, char leftover[BUFFER_SIZE])
{
	char	*buff;
	ssize_t	read_len;
	size_t	line_len;

	buff = malloc(BUFFER_SIZE + 1);
	read_len = read(fd, buff, BUFFER_SIZE);
	while (read_len > 0)
	{
		buff[read_len] = 0;
		line_len = find_line_end(buff);
		if (line_len)
		{
			current = ft_strljoin(current, buff, line_len);
			ft_strncpy(leftover, buff + line_len, read_len - line_len + 1);
			return (free(buff), current);
		}
		current = ft_strljoin(current, buff, read_len);
		if (!current)
			return (free_all(buff, current, leftover));
		read_len = read(fd, buff, BUFFER_SIZE);
	}
	if (read_len < 0)
		return (free_all(buff, current, leftover));
	leftover[0] = 0;
	return (free(buff), current);
}

/**
 * @brief Get a line from a file. 
 * 
 * @details If some extra bytes are read from the last call, it
 * will first try to find a new line character in it. Pass the 
 * new line out if it exists in the extra bytes repository (called
 * leftover). Otherwise, it will read a length of BUFFER_SIZE from 
 * the file repeatedly until it finds a new line character or EOF. 
 * 
 * @param fd the file descriptor to read from
 * @return A new string containing a line from the file descriptor,
 * NUll if any malloc operation in the process fails or invalid 
 * file descriptor is given.
 */
char	*get_next_line(int fd)
{
	static char	leftover[BUFFER_SIZE + 1];
	char		*current;
	size_t		line_len;

	current = NULL;
	if (leftover[0])
	{
		line_len = find_line_end(leftover);
		if (line_len)
		{
			current = ft_strljoin(current, leftover, line_len);
			ft_strncpy(leftover, leftover + line_len, \
				BUFFER_SIZE - line_len + 1);
			return (current);
		}
		current = ft_strdup(leftover);
		if (!current)
			return (free_all(NULL, current, leftover));
	}
	return (main_logic(fd, current, leftover));
}
