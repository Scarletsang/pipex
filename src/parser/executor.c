/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:14:17 by htsang            #+#    #+#             */
/*   Updated: 2022/12/16 18:38:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_parser.h"

int	open_file_from_parser(int permission, t_pipex_parser *parser)
{
	return (
		crash_invalid_fd(
			open(
				get_data(
					parse_filename(parser)), permission), parser));
}

int	execve_command_from_parser(t_pipex_parser *parser)
{
	if (parsing_failed(parse_command(parser)))
	{
		return (1);
	}
	execve(((char **) get_data(parser))[0], \
			(char **) get_data(parser), parser->envp);
	handle_error(parser);
	return (1);
}
