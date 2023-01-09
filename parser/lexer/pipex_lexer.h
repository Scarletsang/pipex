/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_lexer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:59:23 by htsang            #+#    #+#             */
/*   Updated: 2023/01/08 22:30:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_LEXER_H
# define PIPEX_LEXER_H

# include <stdlib.h>
# include "../../libft/pipex_libft.h"

/**
 * @brief The lexer splits a command (as a string) into an array of
 * string. To achieve this, the lexer creates an intermidiate linked
 * list of integers, each node represents the length of an argument.
 * The head of the linked list, however, is different, it saves the
 * amount of arguments required to malloc for the command.
 * 
 * @details The lexer first lexed the command into a linked list,
 * then converter will convert the linked list into an array of 
 * arguments.
 */
typedef struct s_pipex_lexer_node
{
	size_t						length;
	struct s_pipex_lexer_node	*next;
}				t_pipex_lexer_node;

t_pipex_lexer_node	*free_lexer(t_pipex_lexer_node *lexer);

t_pipex_lexer_node	*lex_command(const char *command);

//////////////////////////////////////////
////////      Word consumers    //////////
//////////////////////////////////////////

void				ignore_spaces(char const **str);

void				consume_char(char const **command_args, \
t_pipex_lexer_node *lexer);

const char			*peek_behind_matching_str(const char *match, \
const char *str);

const char			*peek_behind_escape_char(const char *str);

///////////////////////////////////////////////
////////      Strutural consumers    //////////
///////////////////////////////////////////////

t_pipex_lexer_node	*consume_command_arg(char const **command_args, \
t_pipex_lexer_node *lexer);

//////////////////////////////////////////
////////        Converter       //////////
//////////////////////////////////////////

char				**to_split_command(const char *command_args, \
t_pipex_lexer_node *lexer);

int					run_converter_copier(char **split_command, \
const char **command_args, t_pipex_lexer_node *lexer);

#endif