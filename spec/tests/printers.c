/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:52:18 by htsang            #+#    #+#             */
/*   Updated: 2022/12/30 17:52:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	print_split(char **split_str)
{
	int	i;

	i = 0;
	if (!split_str)
	{
		printf("%s", (char *) NULL);
		return ;
	}
	while (split_str[i])
	{
		printf("[%s] ", split_str[i]);
		i++;
	}
}

void	print_lexer_nodes(t_pipex_lexer_node *lexer)
{
	while(lexer)
	{
		printf("[%zu] ", lexer->length);
		lexer = lexer->next;
	}
}

void	print_parser(t_pipex_parser *parser)
{
	print_indentation(4);
	printf("envp:   ");
	print_split((char **) parser->envp);
	print_indentation(4);
	printf("inputs: ");
	print_split((char **) parser->inputs);
	print_indentation(4);
	printf("data:   ");
	if (parser->data_type == COMMAND)
	{
		print_split((char **)parser->data);
		print_indentation(4);
		printf("data_type: COMMAND\n");
	}
	else if (parser->data_type == CONST_STRING)
	{
		printf("%s", (char *)parser->data);
		print_indentation(4);
		printf("data_type: CONST_STRING\n");
	}
}

void	print_states(t_pipex_states *states)
{
	int	i = 0;

	printf("=====================");
	print_indentation(2);
	printf("pipes: ");
	while (i < 4)
	{
		printf("[%d] ", states->pipes[i]);
		i++;
	}
	print_indentation(2);
	printf("last_pipe_index: %d", states->last_pipe_index);
	print_indentation(2);
	printf("parser: ");
	print_parser(&(states->parser));
	printf("=====================");
	
}

void	print_indentation(int n)
{
	printf("\n");
	while (n > 0)
	{
		printf(" ");
		n--;
	}
}