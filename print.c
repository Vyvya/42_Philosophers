/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:35:22 by vgejno            #+#    #+#             */
/*   Updated: 2023/03/02 14:57:27 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg(long int timestamp, t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->data->print_mutex);
	pthread_mutex_lock(philo->data->died_mutex);
	if (philo->data->philo_dead == 0)
	{
		pthread_mutex_unlock(philo->data->died_mutex);
		printf("time[%0.3ldms] philo[%d] %s", timestamp, philo->ph_index, msg);
	}
	else
		pthread_mutex_unlock(philo->data->died_mutex);
	pthread_mutex_unlock(philo->data->print_mutex);
}
