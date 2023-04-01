/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:54:12 by htsang            #+#    #+#             */
/*   Updated: 2023/04/01 21:10:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "pipex_states.h"

void	print_program_error(const char *program_name, const char *error_msg)
{
	if (error_msg)
	{
		write(STDERR_FILENO, program_name, ft_strlen(program_name));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
		write(STDERR_FILENO, "\n", 1);
	}
	else
	{
		perror(program_name);
	}
}

void	print_child_error(const char *program_name, const char *executable, \
const char *error_msg)
{
	write(STDERR_FILENO, program_name, ft_strlen(program_name));
	write(STDERR_FILENO, ": ", 2);
	print_program_error(executable, error_msg);
}

void	print_file_permission_error(t_pipex_states *states)
{
	print_child_error(states->program_name, \
		get_parser_command(get_parser(states))[0], NULL);
}

void	print_command_not_found_error(char *executable, t_pipex_states *states)
{
	print_child_error(states->program_name, executable, "command not found");
}

void	print_no_file_error(t_pipex_states *states)
{
	print_child_error(states->program_name, \
		get_parser_filename(get_parser(states)), NULL);
}
