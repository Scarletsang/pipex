/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:34:22 by htsang            #+#    #+#             */
/*   Updated: 2022/12/22 00:11:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_parser.h"

t_pipex_parser	*parse_command(t_pipex_parser *parser)
{
	char	**split_command;

	split_command = ft_split((parser->commands)[0], ' ');
	if (!split_command)
	{
		return (NULL);
	}
	free_parser_data(parser);
	parser->data = split_command;
	parser->data_need_free = 1;
	return (parser);
}

t_pipex_parser	*parse_filename(t_pipex_parser *parser)
{
	free_parser_data(parser);
	parser->data = (parser->commands)[0];
	parser->data_need_free = 0;
	return (parser);
}

t_pipex_parser	*parser_next_command(t_pipex_parser *parser)
{
	if (parsing_ended(parser))
	{
		return (NULL);
	}
	parser->commands++;
	return (parser);
}

void	free_parser_data(t_pipex_parser *parser)
{
	void	*data;

	if (parser->data_need_free == 1)
	{
		data = parser->data;
		while (*(char **) data)
		{
			free(*(char **) data);
			data++;
		}
		free(data);
	}
}

t_pipex_parser	*init_parser(char const **argv, char *const *envp, \
t_pipex_parser *parser)
{
	parser->envp = envp;
	parser->commands = argv;
	parser->data = NULL;
	parser->data_need_free = 0;
	return (parser);
}
