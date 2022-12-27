/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:52:18 by htsang            #+#    #+#             */
/*   Updated: 2022/12/27 22:07:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	print_split(char **split_str, int indentation)
{
	while (*split_str)
	{
		print_indentation(indentation);
		printf("[%s] ", *split_str);
		split_str++;
	}
}

void	print_lexer_nodes(t_pipex_lexer_node *lexer, int indentation)
{
	while(lexer)
	{
		print_indentation(indentation);
		printf("[%zu] ", lexer->length);
		lexer = lexer->next;
	}
}

void	print_parser(t_pipex_parser *parser, int indentation)
{
	print_indentation(indentation);
	printf("---------------------\n");
	print_indentation(indentation + 2);
	printf("inputs: ");
	print_split((char **) parser->inputs, 0);
	printf("\n");
	print_indentation(indentation + 2);
	printf("data:   ");
	if (parser->data_type == COMMAND)
	{
		print_split((char **)parser->data, 0);
	}
	else if (parser->data_type == CONST_STRING)
	{
		printf("%s", (char *)parser->data);
	}
	printf("\n");
}

void	print_states(t_pipex_states *states, int indentation)
{
	int	i = 0;

	print_indentation(indentation);
	printf("=====================\n");
	indentation += 2;
	print_indentation(indentation);
	printf("pipes: ");
	while (i < 4)
	{
		printf("[%d] ", states->pipes[i]);
		i++;
	}
	printf("\n");
	print_indentation(indentation);
	printf("write_pipe_index: %d\n", states->write_pipe_index);
	print_indentation(indentation);
	printf("parser: \n");
	print_parser(&(states->parser), indentation + 2);
	printf("\n");
	
}

void	print_indentation(int n)
{
	while (n < 0)
	{
		printf(" ");
		n--;
	}
}