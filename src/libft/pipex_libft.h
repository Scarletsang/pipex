/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_libft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:45:21 by htsang            #+#    #+#             */
/*   Updated: 2023/01/02 22:42:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_LIBFT_H
# define PIPEX_LIBFT_H

# include <stdlib.h>

size_t	ft_strlen(const char *str);

char	*ft_strcpy(char *dest, const char *src);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(const char *str, int c);

int		ft_isspace(char c);

#endif