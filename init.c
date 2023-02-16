/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:01 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/16 17:56:55 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_monitoring(t_data data, t_philo *philo)
{
	if (philo->start_last_meal < data.time_to_die)
		printf("philo is dead\n");
}

static void	*ft_philo_eating(t_data data, t_philo *philo)
{
	printf("philo is eating\n");
}

int	ft_init_philo(t_data data, t_philo	*philo)
{
	if (pthread_create(&philo->philo_thread, NULL, &ft_philo_eating, NULL))
		return (-1);
	if (pthread_create(&data.monitor, NULL, &ft_monitoring, NULL))
		return (-1);
	return (0);
}