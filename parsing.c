/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:13 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/17 19:58:59 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	ft_init_thread(void)
// {
// 	pthread_t	the_philo[data->num_philos];
// }



int	ft_parse_init(t_data *data, char **argv)
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
	data->msg_print = create_mutex();
	data->msg_died = create_mutex();
	if (data->msg_print == 0 || data->msg_died == 0)
		return (2);
	data->died = 0;		
	return (0);
}
