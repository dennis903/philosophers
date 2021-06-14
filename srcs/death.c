/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:30:09 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/14 21:42:58 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void			dead_check(t_option *option, t_philo *philo)
{
	philo->latest_time = timestamp();

	if (philo->latest_time - option->latest_time > option->time_to_die)
		option->dead_id = philo->philo_id;
}