/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:34:22 by htsang            #+#    #+#             */
/*   Updated: 2022/12/22 19:03:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_parser.h"

t_pipex_parser	*parser_walk_forward(t_pipex_parser *parser)
{
	if (parsing_ended(parser))
	{
		return (NULL);
	}
	(parser->inputs)++;
	return (parser);
}

t_pipex_parser	*parser_walk_backward(t_pipex_parser *parser)
{
	(parser->inputs)--;
	return (parser);
}

void	free_parser_data(t_pipex_parser *parser)
{
	void	*data;

	if (parser->data_type == COMMAND)
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
	parser->inputs = argv;
	parser->data = NULL;
	parser->data_type = CONST_STRING;
	return (parser);
}
