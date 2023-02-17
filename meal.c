/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:35:22 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/17 18:12:40 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

while (data. > philo->philo_index)
	{
		if (pthread_create(&philo->philo_thread[data.num_philos], NULL, &ft_philo_eating, NULL))
			return (-1);
		data.num_philos--;	
	}
	
	if (pthread_create(&data.monitor, NULL, &ft_monitoring, NULL))
		return (-1);

void	*routine(void *)
{
	t_philo	the_philo;
	
	pthread_mutex_init(&the_philo.l_fork, NULL);
	pthread_mutex_init(&the_philo.r_fork, NULL);
	
	pthread_mutex_lock(&the_philo.l_fork);
	pthread_mutex_unlock(&the_philo.l_fork);

	pthread_mutex_lock(&the_philo.r_fork);
	pthread_mutex_unlock(&the_philo.r_fork);
	
	pthread_mutex_destroy(&the_philo.l_fork);
	pthread_mutex_destroy(&the_philo.r_fork);
}