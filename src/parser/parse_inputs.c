/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:01:05 by htsang            #+#    #+#             */
/*   Updated: 2023/01/09 00:50:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_parser.h"

/**
 * @brief Parse the input in the parser object into an
 * array of command arguments, storing inside the `data`
 * field of the parser object.
 * @param parser the parser object
 * @return the parser object, but with the parsed data stored
 * in the `data` field. Returns NULL if parsing fails.
 */
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

/**
 * @brief Parse the input in the parser object as a filename,
 * storing it directly inside the `data` field of the parser object.
 * @param parser the parser object
 * @return the parser object, but with the parsed data stored
 * in the `data` field.
 */
t_pipex_parser	*parse_filename(t_pipex_parser *parser)
{
	free_parser_data(parser);
	parser->data = (void *)(parser->inputs)[0];
	parser->data_type = CONST_STRING;
	return (parser);
}
