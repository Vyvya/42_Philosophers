/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:35:45 by vgejno            #+#    #+#             */
/*   Updated: 2023/03/02 15:11:43 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_sleeping(t_philo *philo)
{
	unsigned long int	start_tm;
	unsigned long int	tm_now;

	start_tm = get_tm(&(philo->data->tm_launch));
	tm_now = (unsigned long int)start_tm;
	msg(start_tm, philo, BLUE "is sleeping 💤\n" RS);
	while (tm_now - start_tm < (unsigned long int)philo->data->tm_to_sleep)
	{
		usleep(100);
		tm_now = get_tm(&(philo->data->tm_launch));
		if (ft_check_philo_dead(philo))
			return (1);
	}
	return (0);
}
