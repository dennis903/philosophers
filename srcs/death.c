/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:30:09 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/15 22:17:32 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int				death_check(t_option *option, t_philo **philo)
{
	long long	present;

	pthread_mutex_lock(&option->mutex);
	present = option->latest_time - option->first_time;
	present -= (*philo)->latest_eat_time;
	if (present > option->time_to_die)
	{
		print_status(option, (*philo)->philo_id, "died");
		option->dead = 1;
		return (1);
	}
	pthread_mutex_unlock(&option->mutex);
	return (0);
}