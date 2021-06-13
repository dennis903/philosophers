/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:08:36 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/13 18:26:29 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void			init_philos(t_philo **philo)
{
	int			i;
	t_option	tmp;

	i = 0;
	tmp = (*philo)->option;
	while (i < tmp.num_of_philos)
	{
		(*philo)->status = THINKING;
		(*philo)->philo_id = i;
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
	if (!check_valid_arg(argc, option))
		return (FAILED);
	option->philos->option = option;
	init_philos(&(option->philos));
	return (SUCCESS);
}