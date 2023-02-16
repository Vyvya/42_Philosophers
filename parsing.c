/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:13 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/16 17:53:32 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	ft_init_thread(void)
// {
// 	pthread_t	the_philo[data->num_philos];
// }

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

int	ft_check_parse(t_data *data, char **argv)
{
	long int	time;

	data->num_philos = ft_philo_atoi(argv[1]);
	printf("number of philos: %d\n", data->num_philos);
	data->time_to_die = ft_philo_atoi(argv[2]);
	printf("time to die: %d\n", data->time_to_die);
	data->time_to_eat = ft_philo_atoi(argv[3]);
	printf("time to eat: %d\n", data->time_to_eat);
	data->time_to_sleep = ft_philo_atoi(argv[4]);
	printf("time to sleep: %d\n", data->time_to_sleep);
	if (argv[5])
	{
		data->ntime_must_eat = ft_philo_atoi(argv[5]);
		// printf("number of time each philo must eat: %d\n", data->ntime_must_eat);
		if (data->ntime_must_eat < 0)
			return (-1);
		else
			data->ntime_must_eat = -1;
	}
	if (data->num_philos <= 0 || data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
		return (-1);
	// else
	// 	data->times = ft_init_times();	
	ft_get_actual_time();
	return (0);
}
