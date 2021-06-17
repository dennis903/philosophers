/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:53:32 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/17 22:05:11 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int			check_valid_arg(int argc, t_option *option)
{
	if (option->num < 1 || option-> num >= 200)
		return(FAILED);
	if (option->time_to_die < 60)
		return (FAILED);
	if (option->time_to_eat < 60)
		return (FAILED);
	if (option->time_to_sleep < 60)
		return (FAILED);
	if (argc == 6)
		if (option->must_eat <= 0)
			return (FAILED);
	return (SUCCESS);
}