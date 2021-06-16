/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:30:09 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/16 21:56:52 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void				death_check(t_option *option, t_philo **philo)
{
	long long	present;

	pthread_mutex_lock(&option->mutex);
	present = option->latest_time - option->first_time;
	present -= (*philo)->latest_eat_time;
	if (present > option->time_to_die)
	{
		print_status(option, (*philo)->philo_id, "died");
		pthread_mutex_unlock(&option->death);
	}
	pthread_mutex_unlock(&option->mutex);
}