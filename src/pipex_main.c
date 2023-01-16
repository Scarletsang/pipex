/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:33:13 by htsang            #+#    #+#             */
/*   Updated: 2023/01/16 15:41:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes/pipex_processes.h"
#include "heredoc/pipex_heredoc.h"

int	main(int argc, const char **argv, char *const *envp)
{
	t_pipex_states	states;

	if (argc > 1 && is_heredoc(argv[1]))
	{
		return (heredoc_main(argc, argv, envp));
	}
	if (argc < 5)
	{
		write(STDOUT_FILENO, \
			"usage: ./pipex infile cmd1 cmd2 ... outfile\n", 44);
		return (EXIT_FAILURE);
	}
	init_states(argv, envp, &states);
	fork_command_from_infile(&states);
	while (!check_next_command_is_end(get_parser(&states)))
	{
		fork_command(&states);
	}
	return (fork_command_to_outfile(O_TRUNC | O_CREAT | O_RDWR, &states));
}
