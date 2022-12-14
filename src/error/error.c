/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:26:13 by htsang            #+#    #+#             */
/*   Updated: 2022/12/14 19:23:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "error.h"

int	handle_err(int func_return_value) 
{
	if (func_return_value == -1)
	{
		perror(errno);
		exit(EXIT_FAILURE);
	}
	return (func_return_value);
}
