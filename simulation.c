/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:35:22 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/28 13:39:58 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*simu(void *args)
{
	t_philo	*philo_at_table;
	int		i;

	philo_at_table = args;
	i = philo_at_table->max_meals;
	// printf("\nsimulation: i from max_meals: %d\n", i);
	//eternal loop
	while (1)
	{
		if (ft_philo_eating(philo_at_table))
			return (0);
		// printf(MAGENTA "Philo has eaten\n");
		// usleep(10000);	
		if (--i == 0)
		{
			pthread_mutex_lock(philo_at_table->philo_status_mutex);
			philo_at_table->max_meals = 0;
			pthread_mutex_unlock(philo_at_table->philo_status_mutex);
		}
		if (ft_philo_sleeping(philo_at_table))
			return (0);
		// printf(PURPLE "Philo has slept\n");	
		ft_philo_thinking(philo_at_table);
		// printf(PURPLE "Philo has thought\n");	
	}
	return (0);
}
