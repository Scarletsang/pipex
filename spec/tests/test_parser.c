/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:41:46 by htsang            #+#    #+#             */
/*   Updated: 2022/12/27 21:27:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_parser(void)
{
	char			*argv[4];
	t_pipex_parser	*parser;

	argv[0] = "ls -l";
	argv[1] = "ps p 'sdfsdf'";
	argv[2] = "ping www.google.com";
	argv[3] = 0;
	parser = init_parser((const char **) argv, NULL, malloc(sizeof(t_pipex_parser)));
	print_parser(parser);
	parse_command(parser);
	print_parser(parser);
	free_parser_data(parser);
	print_parser(parser);
	free(parser);
}

int	main(void)
{
	test_parser();
	return (0);
}