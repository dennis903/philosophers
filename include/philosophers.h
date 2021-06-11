/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:38:43 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/11 17:49:08 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define INT_MAX 2147483648
# define INT_MIN -2147483647
# define SUCCESS 1
# define FAILED 0
#include <string.h> //for memset
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h> //for gettimeofday
#include <pthread.h>
#include "libft.h"
//error.c
int				error_in_options(int argc, char **argv);
#endif