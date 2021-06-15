/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:08:36 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/15 22:01:52 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int				mutex_init(t_option *option)
{
	int			i;

	i = 0;
	while (i < option->num)
	{
		if (pthread_mutex_init(&(option->fork[i]), NULL))
			return (FAILED);
		i++;
	}
	if (pthread_mutex_init(&(option->mutex), NULL))
		return (FAILED);
	return (SUCCESS);
}

void			init_philos(t_philo *philo, t_option *option)
{
	int			i;
	int			philo_num;

	i = 0;
	philo_num = option->num;
	while (i < option->num)
	{
		philo[i].status = THINKING;
		philo[i].philo_id = i + 1;
		philo[i].option = option;
		philo[i].left_of = (i + (philo_num - 1)) % philo_num;
		philo[i].right_of = i % philo_num;
		philo[i].must_eat = option->must_eat;
		philo[i].latest_eat_time = 0;
		i++;
	}
}

int				init_options(t_option *option, int argc, char **argv)
{
	option->num = ft_atoi(argv[1]);
	option->time_to_die = ft_atoi(argv[2]);
	option->time_to_eat = ft_atoi(argv[3]);
	option->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		option->must_eat = ft_atoi(argv[5]);
	else
		option->must_eat = -1;
	option->dead = 0;
	option->first_time = timestamp();
	if (!check_valid_arg(argc, option))
		return (FAILED);
	if (!mutex_init(option))
		return (FAILED);
	init_philos(option->philos, option);
	return (SUCCESS);
}