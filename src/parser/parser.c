/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:34:22 by htsang            #+#    #+#             */
/*   Updated: 2022/12/14 19:22:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**parse_command(t_pipex_parser *parser)
{
	if (!*(parser->commands))
	{
		return (NULL);
	}
	(parser->commands)++;
	return (ft_split((parser->commands - 1)[0], ' '));
}

char	*parse_filename(t_pipex_parser *parser)
{
	if (!*(parser->commands))
	{
		return (NULL);
	}
	(parser->commands)++;
	return ((parser->commands - 1)[0]);
}

char	*peek_command(t_pipex_parser *parser)
{
	return ((parser->commands)[0]);
}

t_pipex_parser	*init_parser(char const **argv, char *const *envp)
{
	static t_pipex_parser	parser;

	parser.envp = envp;
	parser.commands = argv;
	return (&parser);
}
