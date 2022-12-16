/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:59:23 by htsang            #+#    #+#             */
/*   Updated: 2022/12/16 18:38:16 by htsang           ###   ########.fr       */
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
}               t_pipex_parser;

//////////////////////////////////
////////      parser    //////////
//////////////////////////////////

t_pipex_parser	*parse_command(t_pipex_parser *parser);

t_pipex_parser	*parse_filename(t_pipex_parser *parser);

t_pipex_parser	*init_parser(char const **argv, char *const *envp);

void			*get_data(t_pipex_parser *parser);

void			free_data(t_pipex_parser *parser);

//////////////////////////////////
////      parser state     ///////
//////////////////////////////////

int				parsing_ended(t_pipex_parser *parser);

int				parsing_failed(t_pipex_parser *parser);

//////////////////////////////////
////      crash on error     /////
//////////////////////////////////

void			handle_error(t_pipex_parser *parser);

int				crash_invalid_fd(int func_return_value, t_pipex_parser *parser);

char			*crash_invalid_str(char *func_return_value, t_pipex_parser *parser);

int				crash_when_false(int func_return_value, t_pipex_parser *parser);

////////////////////////////////////////////////
////      execute function from parser     /////
////////////////////////////////////////////////

int	open_file_from_parser(int permission, t_pipex_parser *parser);

int	execve_command_from_parser(t_pipex_parser *parser);

#endif