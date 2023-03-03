/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:32:30 by vgejno            #+#    #+#             */
/*   Updated: 2023/03/02 14:32:48 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philos;

	philos = 0;
	if (ft_parse(&data, argv, argc))
	{
		ft_error("Error parsing invalid argument");
		return (1);
	}
	if (ft_init(&data, &philos))
	{
		free(philos);
		ft_error("Error init philos meassage from main");
		return (2);
	}
	if (ft_join_threads(data.n_philos, philos, &data))
	{
		free(philos);
		return (3);
	}	
	ft_destroy_free_threads(&data, philos);
	return (0);
}
