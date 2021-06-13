/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:36:35 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/13 22:44:58 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void			*act_philo(void *param)
{
	t_philo		philo;
	t_option	*option;

	philo = (*(t_philo *)param);
	option = philo.option;
	while (1)
	{
		pthread_mutex_lock(&option->fork[philo.philo_id]);
		printf("%d :", philo.philo_id);
		printf("hello\n");
		pthread_mutex_unlock(&option->fork[philo.philo_id]);
		sleep(3);
	}
	// eating(philo);
	// sleeping(philo);
	// thinking(philo);
	return (NULL);
}