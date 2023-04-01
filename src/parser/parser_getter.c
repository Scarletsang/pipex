/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_getter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:34:22 by htsang            #+#    #+#             */
/*   Updated: 2023/04/01 21:04:27 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_parser.h"

void	*get_parser_data(t_pipex_parser *parser)
{
	return (parser->data);
}

const char	*get_parser_filename(t_pipex_parser *parser)
{
	return ((const char *) parser->data);
}

char	**get_parser_command(t_pipex_parser *parser)
{
	return ((char **)(parser->data));
}
