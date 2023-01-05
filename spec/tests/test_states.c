/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:41:46 by htsang            #+#    #+#             */
/*   Updated: 2023/01/04 19:53:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_pipex_states	*generate_states(char *const *envp)
{
	char			**argv;
	t_pipex_states	*states;

	argv = malloc(4 * sizeof(char *));
	argv[0] =  "awk '{print $2}'";
	argv[1] = "ps p 'sdfsdf'";
	argv[2] = "ping www.google.com";
	argv[3] = 0;
	states = init_states((const char **) argv, envp);
	// print_states(states);
	return (states);
}

void	test_forking_states(char **argv, char *const *envp)
{
	t_pipex_states	*states;
	t_pipex_parser	*parser;
	pid_t			pid;

	argv++;
	states = init_states((const char **) argv, envp);
	pid = fork();
	if (pid == 0)
	{
		parser = get_parser(states);
		expand_executable_path(parse_command(parser));
		print_states(states);
		execve(get_parser_executable(parser), \
			get_parser_command(parser), parser->envp);
		free_parser_data(parser);
		free(states);
		exit(EXIT_FAILURE);
	}
	wait(NULL);
	print_states(states);
	// free_parser_data(parser);
	free(states);
}

void	test_execve(char *const *envp)
{
	char	*hi[4];

	hi[0] = "/usr/bin/awk";
	hi[1] = "{print $2}";
	hi[2] = "targets/test.txt";
	hi[3] = NULL;
	execve(hi[0], hi, envp);
}

void	test_execve_script(char *const *envp)
{
	char	*hi[2];

	hi[0] = "./targets/script space";
	hi[1] = NULL;
	execve(hi[0], hi, envp);
}

void	test_execve_cd(char *const *envp)
{
	char	*hi[3];

	hi[0] = "cd";
	hi[1] = "..";
	hi[2] = NULL;
	execve(hi[0], hi, envp);
}

int	main(int argc, char **argv, char *const *envp)
{
	if (argc > 0 && argv)
	{
		test_forking_states(argv, envp);
	}
	return (0);
}
