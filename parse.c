/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:13 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/28 16:37:09 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*parse the input string, fill the structure of *data*/

int	ft_parse(t_data *data, char **argv, int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_error("Error wrong number of arguments\n");
		return (1);
	}
	data->n_philos = ft_philo_atoi(argv[1]);
	data->tm_to_die = ft_philo_atoi(argv[2]);
	data->tm_to_eat = ft_philo_atoi(argv[3]);
	data->tm_to_sleep = ft_philo_atoi(argv[4]);
	if (argv[5])
	{
		data->n_must_eat = ft_philo_atoi(argv[5]);
		if (data->n_must_eat < 0)
			return (-1);
	}
	else
		data->n_must_eat = -1;
	if (data->n_philos <= 0 || data->tm_to_die <= 0 || data->tm_to_eat <= 0
		|| data->tm_to_sleep <= 0)
		return (-1);
	return (0);
}
