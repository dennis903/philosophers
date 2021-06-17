/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:38:39 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/17 22:45:31 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int				main(int argc, char *argv[])
{
	t_option	options;

	if (error_in_options(argc, argv))
	{
		if (!init_options(&options, argc, argv))
		{
			printf("error in options\n");
			return (0);
		}
		start_philo(&options);
	}
	else
		printf("error in options\n");
	return (0);
}
