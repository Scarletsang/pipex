/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:59:23 by htsang            #+#    #+#             */
/*   Updated: 2022/12/22 00:14:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PARSER_H
# define PIPEX_PARSER_H

# include "../libft/libft.h"

typedef struct s_pipex_parser
{
	char *const	*envp;
	char		**commands;
	void		*data;
	int			data_need_free;
}				t_pipex_parser;

//////////////////////////////////
////////      parser    //////////
//////////////////////////////////

t_pipex_parser	*parse_command(t_pipex_parser *parser);

t_pipex_parser	*parse_filename(t_pipex_parser *parser);

t_pipex_parser	*parser_next_command(t_pipex_parser *parser);

void			free_parser_data(t_pipex_parser *parser);

t_pipex_parser	*init_parser(char const **argv, char *const *envp, \
t_pipex_parser *parser);

//////////////////////////////////
////      parser state     ///////
//////////////////////////////////

int				parsing_ended(t_pipex_parser *parser);

int				parsing_failed(t_pipex_parser *parser);

void			*get_parser_data(t_pipex_parser *parser);

//////////////////////////////////
////         checker        //////
//////////////////////////////////

int	check_next_command_is_end(t_pipex_parser *parser);

#endif