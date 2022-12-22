/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:44:21 by htsang            #+#    #+#             */
/*   Updated: 2022/12/22 20:11:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_states.h"

void	handle_error(t_pipex_states *states)
{
	perror(errno);
	free_parser_data(get_parser(states));
}

int	crash_when_minus_1(int func_return_value, t_pipex_states *states)
{
	if (func_return_value == -1)
	{
		handle_error(states);
		free(states);
		exit(EXIT_FAILURE);
	}
	return (func_return_value);
}

char	*crash_invalid_str(char *func_return_value, t_pipex_states *states)
{
	if (func_return_value == NULL)
	{
		handle_error(states);
		free(states);
		exit(EXIT_FAILURE);
	}
	return (func_return_value);
}

int	crash_when_false(int func_return_value, t_pipex_states *states)
{
	if (func_return_value == 0)
	{
		handle_error(states);
		free(states);
		exit(EXIT_FAILURE);
	}
	return (func_return_value);
}
