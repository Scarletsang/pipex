/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:34:22 by htsang            #+#    #+#             */
/*   Updated: 2023/04/01 19:29:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_parser.h"

t_pipex_parser	*parser_walk_forward(t_pipex_parser *parser)
{
	if (!parser || parsing_ended(parser))
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
	size_t	i;

	if (parser->data_type == CONST_STRING)
	{
		return ;
	}
	if (parser->data_type == COMMAND)
	{
		i = 0;
		while (((char **) parser->data)[i])
		{
			free(((char **) parser->data)[i]);
			i++;
		}
		free(parser->data);
		parser->data = NULL;
		parser->data_type = CONST_STRING;
	}
}

t_pipex_parser	*init_parser(char const **argv, t_pipex_parser *parser)
{
	parser->inputs = argv;
	parser->data = NULL;
	parser->data_type = CONST_STRING;
	return (parser);
}
