/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:34:22 by htsang            #+#    #+#             */
/*   Updated: 2022/12/22 00:01:04 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_parser.h"

int	parsing_ended(t_pipex_parser *parser)
{
	return (parser->commands == NULL);
}

int	parsing_failed(t_pipex_parser *parser)
{
	return (parser == NULL);
}

void	*get_parser_data(t_pipex_parser *parser)
{
	return (parser->data);
}
