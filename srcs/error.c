/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:44:23 by hyeolee           #+#    #+#             */
/*   Updated: 2021/06/13 20:22:07 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int		check_num(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '0' && ft_strlen(str) == 1)
			return (FAILED);
		if (str[i] < '0' || str[i] > '9')
			return (FAILED);
		i++;
	}
	return (SUCCESS);
}

static int		is_valid_number(char *str)
{
	int			i;

	i = 1;
	if (!check_num(str))
		return (FAILED);
	return (SUCCESS);
}


static int		is_in_int_max(char *str)
{
	long long	num;
	int			i;

	i = 1;
	num = ft_atoi(str);
	if (num > INT_MAX)
		return (FAILED);
	return (SUCCESS);
}

static int		check_error_in_number(char *str)
{
	if (!is_valid_number(str))
		return (FAILED);
	if (!is_in_int_max(str))
		return (FAILED);
	return (SUCCESS);
}

int				error_in_options(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (FAILED);
	if (!check_error_in_number(argv[1]))
		return (FAILED);
	if (!check_error_in_number(argv[2]))
		return (FAILED);
	if (!check_error_in_number(argv[3]))
		return (FAILED);
	if (!check_error_in_number(argv[4]))
		return (FAILED);
	if (argc == 6)
		if (!check_error_in_number(argv[5]))
			return (FAILED);
	return (SUCCESS);
}