/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:41:51 by htsang            #+#    #+#             */
/*   Updated: 2022/12/28 21:36:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include "../../src/processes/pipex_processes.h"

void	print_split(char **split_str);

void	print_lexer_nodes(t_pipex_lexer_node *lexer);

void	print_parser(t_pipex_parser *parser);

void	print_states(t_pipex_states *states);

void	print_indentation(int n);

#endif