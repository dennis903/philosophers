/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:36:35 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/13 18:28:15 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void			*act_philo(t_philo *philo)
{
	death_check(philo);
	//todo : eating
	death_check(philo);
	//todo : sleeping
	death_check(philo);
	//todo : thinking
	death_check(philo);
}