/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_expander.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:25:40 by htsang            #+#    #+#             */
/*   Updated: 2022/12/29 23:47:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pipex_path_expander.h"

static char	*expand_path(char const **path_envp, \
char *executable_name, size_t executable_name_len)
{
	char	*expanded_path;
	size_t	i;

	expanded_path = malloc(ft_expanded_pathlen(*path_envp, \
	executable_name_len) + 1);
	if (!expanded_path)
	{
		return (NULL);
	}
	i = 0;
	while (**path_envp)
	{
		if (**path_envp == ':')
		{
			(*path_envp)++;
			break ;
		}
		expanded_path[i++] = **path_envp;
		(*path_envp)++;
	}
	expanded_path[i++] = '/';
	ft_strcpy(expanded_path + i, executable_name);
	return (expanded_path);
}

static int	is_path_envp(const char *env)
{
	char const	*match;

	match = "PATH=";
	while (*match && *env)
	{
		if (*env != *match)
		{
			return (0);
		}
		match++;
		env++;
	}
	return (1);
}

static char const	*get_parser_path_envp(t_pipex_parser *parser)
{
	char *const	*envp;

	envp = parser->envp;
	while (*envp)
	{
		if (is_path_envp(*envp))
		{
			return (*envp + 5);
		}
		envp++;
	}
	return (NULL);
}

static t_pipex_parser	*set_expanded_path(char *expanded_path, \
t_pipex_parser *parser)
{
	free(get_parser_executable(parser));
	*((char **) parser->data) = expanded_path;
	return (parser);
}

t_pipex_parser	*expand_executable_path(t_pipex_parser *parser)
{
	char const	*path_envp;
	char		*expanded_path;
	char		*executable_name;
	size_t		executable_name_len;

	if (!parser)
		return (NULL);
	path_envp = get_parser_path_envp(parser);
	if (!path_envp)
		return (NULL);
	executable_name = get_parser_executable(parser);
	executable_name_len = ft_strlen(executable_name);
	while (*path_envp)
	{
		expanded_path = expand_path(&path_envp, \
		executable_name, executable_name_len);
		if (!expanded_path)
			return (NULL);
		if (access(expanded_path, F_OK) == 0)
		{
			return (set_expanded_path(expanded_path, parser));
		}
		free(expanded_path);
	}
	return (NULL);
}
