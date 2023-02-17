/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:27 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/17 19:11:22 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*create mutex and returns a poniter to it. crt_mutex() creates a new 
mutex object and returns a pointer to it. The fill_philo() function is then
using crt_mutex() twice to create two separate mutex objects: philo->r_fork 
and philo->philo_auto_check.
Calling crt_mutex() twice in the fill_philo() function creates two separate 
mutex objects.*/
pthread_mutex_t	*create_mutex(void)
{
	pthread_mutex_t	*gen_mutex;

	gen_mutex = malloc(sizeof(pthread_mutex_t) * 1);
	if (gen_mutex == 0)
		return (ft_error("Error malloc mutex"));
	pthead_mutex_init(gen_mutex, 0);
	return (gen_mutex);
}

int	ft_philo_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (*str == '-')
		return (ft_error("Error argument is negatif"));
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + *str - '0';
		else
			return (ft_error("Error argument not number"));
		str++;
	}
	if (res > INT_MAX || res <= INT_MIN)
		return (ft_error("Error argument is negatif"));
	return (res);
}
