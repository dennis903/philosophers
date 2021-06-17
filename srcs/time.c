/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:51:58 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/17 22:47:33 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void				ft_usleep(long long save, long long time)
{
	long long		wait;

	while (timestamp() < save + time)
	{
		wait = (save + time - timestamp()) / 2;
		usleep(wait * 1000);
	}
}

long long			timediff(long long present, long long first)
{
	return (present - first);
}

long long			timestamp(void)
{
	struct timeval	time;
	long long		present;

	gettimeofday(&time, NULL);
	present = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (present);
}
