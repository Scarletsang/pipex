/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:41:46 by htsang            #+#    #+#             */
/*   Updated: 2023/01/02 23:26:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_parser(char *const *envp)
{
	char			*argv[4];
	t_pipex_parser	*parser;

	argv[1] = "echo \"hel\\\"lo\"";
	argv[0] = "script\\ name -l";
	argv[2] = "ping www.google.com";
	argv[3] = 0;
	parser = init_parser((const char **) argv, envp, malloc(sizeof(t_pipex_parser)));
	print_parser(parser);
	parse_command(parser);
	print_parser(parser);
	expand_executable_path(parser);
	print_parser(parser);
	free_parser_data(parser);
	print_parser(parser);
	free(parser);
}

int	main(int argc, char **argv, char *const *envp)
{
	if (argc > 0 && argv)
	{
		test_parser(envp);
	}
	return (0);
}