/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:36:35 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/14 22:13:48 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void			print_status(t_option *option, int pid, const char *status)
{
	printf("%lld ms %d %s\n",option->latest_time, pid, status);
}

void			sleeping(t_philo *philo)
{
	t_option	*option;

	option = philo->option;
	if (philo->status == EATING)
	{
		philo->status = SLEEPING;
		print_status(option, philo->philo_id, "is sleeping");
		usleep(option->time_to_sleep * 1000);
	}
}

void			thinking(t_philo *philo)
{
	t_option	*option;

	option = philo->option;
	if (philo->status == SLEEPING)
	{
		philo->status = THINKING;
		print_status(option, philo->philo_id, "is sleeping");
	}
}

void			eating(t_philo *philo)
{
	t_option	*option;

	option = philo->option;
	if (philo->status == THINKING)
	{
		pthread_mutex_lock(&option->fork[philo->left_of]);
		option->latest_time = timestamp();
		print_status(option, philo->philo_id, "has taken a fork");
		pthread_mutex_lock(&option->fork[philo->right_of]);
		option->latest_time = timestamp();
		print_status(option, philo->philo_id, "has taken a fork");
		option->latest_time = timestamp();
		philo->status = EATING;
		print_status(option, philo->philo_id, "is eating");
		philo->must_eat--;
		usleep(option->time_to_eat * 1000);
		pthread_mutex_unlock(&option->fork[philo->left_of]);
		pthread_mutex_unlock(&option->fork[philo->right_of]);
	}
}

void			*act_philo(void *param)
{
	t_philo		*philo;
	t_option	*option;

	philo = (t_philo *)param;
	option = philo->option;
	while (option->dead_id == -1 || philo->must_eat > 0)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}