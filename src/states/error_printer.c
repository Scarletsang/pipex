/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:54:12 by htsang            #+#    #+#             */
/*   Updated: 2023/01/05 01:33:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "pipex_states.h"

void	print_not_found_error(char *executable, t_pipex_states *states)
{
	write(STDERR_FILENO, states->program_name, \
		ft_strlen(states->program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, executable, ft_strlen(executable));
	write(STDERR_FILENO, ": command not found\n", 20);
}

void	print_no_file_error(t_pipex_states *states)
{
	const char	*file_name;
	char		*error_msg;

	file_name = get_parser_filename(get_parser(states));
	error_msg = strerror(errno);
	write(STDERR_FILENO, states->program_name, \
		ft_strlen(states->program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, file_name, ft_strlen(file_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
}
