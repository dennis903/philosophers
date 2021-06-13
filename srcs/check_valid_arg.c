/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:53:32 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/13 15:57:40 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int			check_valid_arg(int argc, t_option *option)
{
	if (option->num_of_philos < 2)
		return(FAILED);
	if (option->time_to_die <= 0)
		return (FAILED);
	if (option->time_to_eat <= 0)
		return (FAILED);
	if (option->time_to_sleep <= 0)
		return (FAILED);
	if (argc == 6)
		if (option->num_of_philos_eat <= 0)
			return (FAILED);
	return (SUCCESS);
}