/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:03:41 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/15 18:56:00 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void		start_philo(t_option *option)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = option->philos;
	// while (i < option->num)
	// {
	// 	printf("%d : %d\n", philo[i].philo_id, philo[i].left_of);
	// 	printf("%d : %d\n", philo[i].philo_id, philo[i].right_of);
	// 	i++;
	// }
	while (i < option->num)
	{
		pthread_create(&philo[i].tid, NULL, act_philo, (void *)&philo[i]);
		i++;
	}
	i = 0;
	while (i < option->num)
	{
		pthread_join(philo[i].tid, NULL);
		i++;
	}
	// monitor();
	// exit_philo();
}