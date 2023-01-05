/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_lexer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:59:23 by htsang            #+#    #+#             */
/*   Updated: 2023/01/06 00:34:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_LEXER_H
# define PIPEX_LEXER_H

# include <stdlib.h>
# include "../../libft/pipex_libft.h"

typedef struct s_pipex_lexer_node
{
	size_t						length;
	struct s_pipex_lexer_node	*next;
}				t_pipex_lexer_node;

void				ignore_spaces(char const **str);

t_pipex_lexer_node	*free_lexer(t_pipex_lexer_node *lexer);

void				consume_char(char const **command_args, \
t_pipex_lexer_node *lexer);

t_pipex_lexer_node	*consume_command_arg(char const **command_args, \
t_pipex_lexer_node *lexer);

t_pipex_lexer_node	*lex_command(const char *command);

char				**to_split_command(const char *command_args, \
t_pipex_lexer_node *lexer);

int					run_converter_copier(char **split_command, \
const char **command_args, t_pipex_lexer_node *lexer);

const char			*get_escape_char(const char *str);

#endif