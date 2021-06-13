/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:38:43 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/13 18:31:43 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define INT_MAX 2147483648
# define INT_MIN -2147483647
# define SUCCESS 1
# define FAILED 0
# define EATING 1
# define THINKING 2
# define SLEEPING 3
# define DEAD 4
#include <string.h> //for memset
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h> //for gettimeofday
#include <pthread.h>

typedef struct		s_option;

typedef	struct		s_philo
{
	int				status;
	int				philo_id;
	struct s_option	option;
	pthread_mutex_t	eat_check;
}					t_philo;

typedef struct		s_option
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_philos_eat;
	pthread_t		tid[200];
	pthread_mutex_t	fork[200];
	t_philo			philos[200];
}					t_option;

int					error_in_options(int argc, char **argv);
int					init_options(t_option *option, int argc, char **argv);
int					check_valid_arg(int argc, t_option *option);
void				start_philo(t_option *option);
void				*act_philo(t_philo *philo);
#endif