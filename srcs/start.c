/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:03:41 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/14 22:26:46 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void		start_philo(t_option *option)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = option->philos;
	option->latest_time = timestamp();
	// while (i < option->num)
	// {
	// 	pthread_create(&philo[i].tid, NULL, act_philo, (void *)&philo[i]);
	// 	i++;
	// }
	// i = 0;
	// while (i < option->num)
	// {
	// 	pthread_join(philo[i].tid, NULL);
	// 	i++;
	// }
	//monitor();
	//exit_philo();
}