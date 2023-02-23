/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:35:22 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/23 19:21:59 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_sleeping(t_philo *philo)
{
	printf("Sleeping");
}

void *simulation(void *args)
{
	t_philo	*philo_at_table;
	int		i;
	
	philo_at_table = args;
	i = philo_at_table->max_meals;
	//eternal loop
	while (1)
	{
		if (ft_philo_eating(philo_at_table))
			return (0);
		if (--i == 0)
		{
			pthread_mutex_lock(philo_at_table->philo_status_mutex);
			philo_at_table->philo_index = 0;
			pthread_mutex_unlock(philo_at_table->philo_status_mutex);
		}
		if (ft_philo_sleeping(philo_at_table))
			return (0);
	}
}
