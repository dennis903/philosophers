/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:03:41 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/13 22:42:34 by hyeolee          ###   ########.fr       */
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
		pthread_create(&philo[i].tid, NULL, act_philo, (void *)&philo[i]);
		i++;
	}
	i = 0;
	while (1)
	{
		printf("main :%d\n", i);
		sleep(3);
		i++;
	}
	//dead_check()
	//exit()
}