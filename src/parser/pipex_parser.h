/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:59:23 by htsang            #+#    #+#             */
/*   Updated: 2022/12/29 22:23:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PARSER_H
# define PIPEX_PARSER_H

# include "lexer/pipex_lexer.h"

typedef enum e_data_type
{
	CONST_STRING,
	COMMAND
}				t_data_type;

typedef struct s_pipex_lexer
{
	size_t					length;
	struct s_pipex_lexer	*next;
}					t_pipex_lexer;

typedef struct s_pipex_parser
{
	char *const	*envp;
	const char	**inputs;
	void		*data;
	t_data_type	data_type;
}				t_pipex_parser;

//////////////////////////////////
////////      parser    //////////
//////////////////////////////////

t_pipex_parser	*parser_walk_forward(t_pipex_parser *parser);

t_pipex_parser	*parser_walk_backward(t_pipex_parser *parser);

void			free_parser_data(t_pipex_parser *parser);

t_pipex_parser	*init_parser(char const **argv, char *const *envp, \
t_pipex_parser *parser);

//////////////////////////////////
/////      parse inputs    ///////
//////////////////////////////////

t_pipex_parser	*parse_command(t_pipex_parser *parser);

t_pipex_parser	*parse_filename(t_pipex_parser *parser);

//////////////////////////////////
////      parser getters     /////
//////////////////////////////////

void			*get_parser_data(t_pipex_parser *parser);

char			**get_parser_command(t_pipex_parser *parser);

char			*get_parser_executable(t_pipex_parser *parser);

//////////////////////////////////
////         checker        //////
//////////////////////////////////

int				check_next_command_is_end(t_pipex_parser *parser);

int				parsing_ended(t_pipex_parser *parser);

int				parsing_failed(t_pipex_parser *parser);

#endif