/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:59:23 by htsang            #+#    #+#             */
/*   Updated: 2022/12/14 19:22:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/libft.h"

typedef struct s_pipex_parser
{
	char *const	*envp;
	char 		    **commands;
}               t_pipex_parser;

char			**parse_command(t_pipex_parser *parser);

char			*parse_filename(t_pipex_parser *parser);

char			*peek_command(t_pipex_parser *parser);

t_pipex_parser	*init_parser(char const **argv, char *const *envp);

#endif