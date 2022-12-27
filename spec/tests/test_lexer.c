/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:41:46 by htsang            #+#    #+#             */
/*   Updated: 2022/12/27 20:54:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_lexer_and_converter(void)
{
	char	command[] = "ls 'ps hi'";
	char	**split_str;

	split_str = to_split_command(command, lex_command(command));
	print_split(split_str);
}

void	test_lexer(void)
{
	char	command[] = "lskkk ps hi45";
	t_pipex_lexer_node	*lexer;

	lexer = lex_command(command);
	print_lexer_nodes(lexer);
}

int	main(void)
{
	test_lexer_and_converter();
	return (0);
}