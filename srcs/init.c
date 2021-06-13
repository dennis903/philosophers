/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:08:36 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/13 22:30:21 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int				mutex_init(t_option *option)
{
	int			i;

	i = 0;
	while (i < option->num_of_philos)
	{
		if (pthread_mutex_init(&(option->fork[i]), NULL))
			return (FAILED);
		i++;
	}
	return (SUCCESS);
}

void			init_philos(t_philo *philo, t_option *option)
{
	int			i;

	i = 0;
	while (i < option->num_of_philos)
	{
		philo[i].status = THINKING;
		philo[i].philo_id = i;
		philo[i].option = option;
		i++;
	}
}

int				init_options(t_option *option, int argc, char **argv)
{
	option->num_of_philos = ft_atoi(argv[1]);
	option->time_to_die = ft_atoi(argv[2]);
	option->time_to_eat = ft_atoi(argv[3]);
	option->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		option->num_of_philos_eat = ft_atoi(argv[5]);
	else
		option->num_of_philos_eat = -1;
	option->first_time = timestamp();
	if (!check_valid_arg(argc, option))
		return (FAILED);
	if (!mutex_init(option))
		return (FAILED);
	init_philos(option->philos, option);
	return (SUCCESS);
}