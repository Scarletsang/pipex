/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:44:21 by htsang            #+#    #+#             */
/*   Updated: 2022/12/16 18:38:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "pipex_parser.h"

void	handle_error(t_pipex_parser *parser)
{
	perror(errno);
	free_data(parser);
}

int	crash_invalid_fd(int func_return_value, t_pipex_parser *parser)
{
	if (func_return_value == -1)
	{
		handle_error(parser);
		free(parser);
		exit(EXIT_FAILURE);
	}
	return (func_return_value);
}

char	*crash_invalid_str(char *func_return_value, t_pipex_parser *parser)
{
	if (func_return_value == NULL)
	{
		handle_error(parser);
		free(parser);
		exit(EXIT_FAILURE);
	}
	return (func_return_value);
}

int	crash_when_false(int func_return_value, t_pipex_parser *parser)
{
	if (func_return_value == 0)
	{
		handle_error(parser);
		free(parser);
		exit(EXIT_FAILURE);
	}
	return (func_return_value);
}
