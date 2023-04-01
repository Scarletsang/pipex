/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_expander.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:25:40 by htsang            #+#    #+#             */
/*   Updated: 2023/04/01 21:10:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pipex_parser.h"

extern char	**environ;

static size_t	ft_expanded_pathlen(char const *path_envp, \
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

static char const	*get_parser_path_envp(void)
{
	char *const	*envp;

	envp = environ;
	while (*envp)
	{
		if (peek_behind_matching_str("PATH=", *envp))
		{
			return (*envp + 5);
		}
		envp++;
	}
	return (NULL);
}

/**
 * @brief Concatenate the a path to an executable name.
 * @param path_envp the PATH enironmental varaible as a string
 * @param executable_name name of the executable
 * @param executable_name_len length of the executable name
 * @return A new string with the executable name expanded with a path
 */
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

/**
 * @brief In order to run a command in execve(), it has to be expanded
 * to a path to an executable with the same name. This function gets the
 * PATHs from the environmental variables stored in the parser object, 
 * and try to look for an executable name that are accessible in the
 * `data` field of the parser object.
 * @param parser 
 * @return the parser object with the executable in the data expanded,
 * or NULL if the executable is not found in PATH.
 */
char	*expand_executable_path(t_pipex_parser *parser)
{
	char const	*path_envp;
	char		*expanded_path;
	char		*executable_name;
	size_t		executable_name_len;

	if (!parser)
		return (NULL);
	path_envp = get_parser_path_envp();
	if (!path_envp)
		return (NULL);
	executable_name = get_parser_command(parser)[0];
	executable_name_len = ft_strlen(executable_name);
	while (*path_envp)
	{
		expanded_path = expand_path(&path_envp, \
		executable_name, executable_name_len);
		if (!expanded_path)
			return (NULL);
		if (access(expanded_path, F_OK) == 0)
		{
			return (expanded_path);
		}
		free(expanded_path);
	}
	return (NULL);
}
