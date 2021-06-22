/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:36:35 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/22 12:37:00 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void			print_status(t_option *option, int pid, const char *status)
{
	long long	present;

	pthread_mutex_lock(&option->print_mutex);
	present = timediff(timestamp(), option->first_time);
	if (option->dead == 0)
		printf("%lld ms %d %s\n", present, pid, status);
	else if (strcmp(status, "died") == 0)
		printf("%lld ms %d %s\n", present, pid, status);
	pthread_mutex_unlock(&option->print_mutex);
}

void			sleeping(t_philo **philo)
{
	t_option	*option;

	option = (*philo)->option;
	if ((*philo)->status == EATING)
	{
		(*philo)->status = SLEEPING;
		print_status(option, (*philo)->philo_id, "is sleeping");
		option->latest_time = timestamp();
		ft_usleep(option->latest_time, option->time_to_sleep);
	}
}

void			thinking(t_philo **philo)
{
	t_option	*option;

	option = (*philo)->option;
	if ((*philo)->status == SLEEPING)
	{
		(*philo)->status = THINKING;
		print_status(option, (*philo)->philo_id, "is thinking");
	}
}

void			eating(t_philo **philo)
{
	t_option	*option;

	option = (*philo)->option;
	if ((*philo)->status == THINKING)
	{
		pthread_mutex_lock(&option->fork[(*philo)->left_of]);
		option->latest_time = timestamp();
		print_status(option, (*philo)->philo_id, "has taken a left fork");
		pthread_mutex_lock(&option->fork[(*philo)->right_of]);
		option->latest_time = timestamp();
		print_status(option, (*philo)->philo_id, "has taken a right fork");
		pthread_mutex_lock(&option->death);
		option->latest_time = timestamp();
		(*philo)->status = EATING;
		print_status(option, (*philo)->philo_id, "is eating");
		(*philo)->eat_count++;
		pthread_mutex_unlock(&option->death);
		ft_usleep(option->latest_time, option->time_to_eat);
		(*philo)->latest_eat_time = timestamp();
		pthread_mutex_unlock(&option->fork[(*philo)->left_of]);
		pthread_mutex_unlock(&option->fork[(*philo)->right_of]);
	}
}

void			*act_philo(void *param)
{
	t_philo		*philo;
	t_option	*option;

	philo = (t_philo *)param;
	option = philo->option;
	if (philo->philo_id % 2 == 0)
		ft_usleep(timestamp(), option->time_to_eat);
	while ((philo->eat_count != option->must_eat) && option->dead == 0)
	{
		eating(&philo);
		sleeping(&philo);
		thinking(&philo);
	}
	if (philo->eat_count == option->must_eat)
		philo->all_ate = 1;
	return (NULL);
}
