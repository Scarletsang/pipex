/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:01:05 by htsang            #+#    #+#             */
/*   Updated: 2022/12/26 00:25:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_parser.h"

t_pipex_parser	*parse_command(t_pipex_parser *parser)
{
	char	**split_command;

	split_command = to_split_command((parser->inputs)[0], \
		lex_command((parser->inputs)[0]));
	if (!split_command)
	{
		return (NULL);
	}
	free_parser_data(parser);
	parser->data = split_command;
	parser->data_type = COMMAND;
	return (parser);
}

t_pipex_parser	*parse_filename(t_pipex_parser *parser)
{
	free_parser_data(parser);
	parser->data = (void *)(parser->inputs)[0];
	parser->data_type = CONST_STRING;
	return (parser);
}
