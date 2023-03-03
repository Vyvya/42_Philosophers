/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:27 by vgejno            #+#    #+#             */
/*   Updated: 2023/03/02 14:37:25 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_philo_atoi(char *str)
{
	long int	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == '-')
		return (-1);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + *str - '0';
		else
			return (-1);
		str++;
	}
	if (res > INT_MAX || res < INT_MIN)
	{
		ft_error("Error argument INT_MAX INT_MIN");
		return (-1);
	}		
	return (res);
}
