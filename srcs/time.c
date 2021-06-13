/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:51:58 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/13 20:26:05 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long long			timestamp(void)
{
	struct timeval	mytime;

	gettimeofday(&mytime, NULL);
	return (mytime.tv_usec);
}