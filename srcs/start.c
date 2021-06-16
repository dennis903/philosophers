/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:03:41 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/16 21:56:25 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void		start_philo(t_option *option)
{
	int		i;
	t_philo	*philo;


	i = 0;
	philo = option->philos;
	pthread_mutex_lock(&option->death);
	while (i < option->num)
	{
		pthread_create(&philo[i].tid, NULL, act_philo, (void *)&philo[i]);
		i++;
	}
	pthread_mutex_lock(&option->death);
	exit(0);
}