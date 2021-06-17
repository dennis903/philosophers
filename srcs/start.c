/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:03:41 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/17 22:45:06 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void			destroy_mutex(t_option *option)
{
	int			i;

	i = 0;
	while (i < option->num)
	{
		pthread_mutex_destroy(&option->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&option->death);
	pthread_mutex_destroy(&option->print_mutex);
}

void			start_philo(t_option *option)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = option->philos;
	option->first_time = timestamp();
	while (i < option->num)
	{
		pthread_create(&philo[i].tid, NULL, act_philo, (void *)&philo[i]);
		pthread_detach(philo[i].tid);
		i++;
	}
	monitor(option, philo);
	destroy_mutex(option);
}
