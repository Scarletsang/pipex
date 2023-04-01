/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:59:23 by htsang            #+#    #+#             */
/*   Updated: 2023/04/01 21:09:22 by htsang           ###   ########.fr       */
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

/**
 * @brief A parser object that keeps track of the unparsed
 * commands, and the environmental variable that is needed during
 * parsing. The parsed command is saved in the 'data' field, and
 * the 'data_type' corresponds to the type of the data so parser
 * knows whether or not to free it when the program ends.
 */
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

t_pipex_parser	*init_parser(char const **argv, t_pipex_parser *parser);

//////////////////////////////////
/////      parse inputs    ///////
//////////////////////////////////

t_pipex_parser	*parse_command(t_pipex_parser *parser);

t_pipex_parser	*parse_filename(t_pipex_parser *parser);

//////////////////////////////////
////      parser getters     /////
//////////////////////////////////

void			*get_parser_data(t_pipex_parser *parser);

const char		*get_parser_filename(t_pipex_parser *parser);

char			**get_parser_command(t_pipex_parser *parser);

//////////////////////////////////
////         checker        //////
//////////////////////////////////

int				check_next_command_is_end(t_pipex_parser *parser);

int				parsing_ended(t_pipex_parser *parser);

int				parsing_failed(t_pipex_parser *parser);

////////////////////////////////////
////       Path expander       /////
////////////////////////////////////

char			*expand_executable_path(t_pipex_parser *parser);

#endif