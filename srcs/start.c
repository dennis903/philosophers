/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:03:41 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/13 18:26:45 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void		start_philo(t_option *option)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = option->philos;
	while (i < option->num_of_philos)
	{
		pthread_create(&option->tid[i], NULL, act_philo, philo);
		i++;
	}
	i = 0;
	while (i < option->num_of_philos)
	{
		pthread_join(option->tid[i], NULL);
		i++;
	}
}