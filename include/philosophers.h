/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:38:43 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/15 22:01:48 by hyeolee          ###   ########.fr       */
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

struct s_option;

typedef	struct		s_philo
{
	int				status;
	int				philo_id;
	int				left_of;
	int				right_of;
	int				must_eat;
	int				latest_eat_time;
	long long		latest_time;
	pthread_t		tid;
	struct s_option	*option;
}					t_philo;

typedef struct		s_option
{
	int				num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				dead;
	long long		latest_time;
	long long		first_time;
	pthread_mutex_t	mutex;
	pthread_mutex_t	fork[200];
	struct s_philo	philos[200];
}					t_option;


int					error_in_options(int argc, char **argv);
int					init_options(t_option *option, int argc, char **argv);
int					check_valid_arg(int argc, t_option *option);
void				start_philo(t_option *option);
void				*act_philo(void *param);
long long			timestamp(void);
size_t				ft_strlen(const char *s);
long long			ft_atoi(const char *str);
int					death_check(t_option *option, t_philo **philo);
long long			timediff(long long present, long long first);
void				ft_usleep(long long save, long long time);
int					pickup(t_option *option, t_philo **philo);
void				print_status(t_option *option, int pid, const char *status);
#endif