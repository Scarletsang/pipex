/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:09:02 by htsang            #+#    #+#             */
/*   Updated: 2022/12/22 00:13:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_parser.h"

int	check_next_command_is_end(t_pipex_parser *parser)
{
	return (parser->commands + 1 == NULL);
}
