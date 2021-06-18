/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:30:09 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/18 20:40:52 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int				check_death(t_option *op, long long recent, t_philo *philo)
{
	long long	eat_time;

	eat_time = philo->latest_eat_time;
	if (philo->all_ate == 1)
		return (0);
	if ((recent - eat_time) > op->time_to_die)
		return (1);
	else
		return (0);
}

int				check_all_ate(t_option *option, t_philo *philo)
{
	int			i;

	i = 0;
	while (i < option->num)
	{
		if (philo[i].eat_count != option->must_eat)
			break ;
		i++;
	}
	if (i == option->num)
		return (1);
	return (0);
}

void			monitor(t_option *option, t_philo *philo)
{
	int			i;

	while (option->all_ate == 0 && option->dead == 0)
	{
		i = 0;
		while (i < option->num && option->dead == 0)
		{
			pthread_mutex_lock(&option->death);
			if (check_death(option, timestamp(), &philo[i]))
			{
				option->dead = 1;
				option->latest_time = timestamp();
				print_status(option, philo[i].philo_id, "died");
			}
			pthread_mutex_unlock(&option->death);
			i++;
		}
		option->all_ate = check_all_ate(option, philo);
	}
}
