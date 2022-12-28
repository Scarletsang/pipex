/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_expander.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:25:40 by htsang            #+#    #+#             */
/*   Updated: 2022/12/29 00:33:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pipex_path_expander.h"

/**
** @param str: a NULL-terminated string
** @return the length of the given string
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

static size_t	calc_executable_name_len(size_t executable_name_len, \
char const *path_envp)
{
	// executable name length
	// '/' character length
	// path length
}

static char const	*expand_path(size_t executable_name_len, \
t_pipex_parser *parser)
{
	// malloc (exec_len + path_len + 2)
	// copy from path_envp up to : or \0
	// write '\' character
	// copy executable name
	// write NULL terminator
}

static char const	*get_parser_PATH_envp(t_pipex_parser *parser)
{
	char const	*match;
	char *const *envp;

	match = "PATH=";
	envp = parser->envp;
	while (*envp)
	{
		if (/* check envp starts with the match string */)
		{
			return (*envp + 5);
		}
		envp++;
	}
	return (NULL);
}

t_pipex_parser	*expand_executable_path(t_pipex_parser *parser)
{
	char const	*path_envp;
	char		*expanded_executable_path;
	size_t		executable_name_len;

	if (!parser)
	{
		return (NULL);
	}
	path_envp = get_parser_PATH_envp(parser);
	executable_name_len = ft_strlen(((const char **) (parser->data))[0]);
	expanded_executable_path = NULL;
	while (*path_envp)
	{
		expanded_executable_path = expand_path(executable_name_len, parser);
		if (access(expanded_executable_path, F_OK))
		{
			// free first element of parser data
			// set it to the expanded_path
			// return parser
		}
		//free expanded_path, and continue the loop
	}
	return (NULL);
}
