/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:00:30 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/28 16:47:18 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mysleep(t_philo *philo, long int tm_to_die)
{
	long int	start_tm;
	long int	tm_now;

	start_tm = ft_tm_passed(&(philo->data->tm_launch));
	tm_now = start_tm;
	while (tm_now - start_tm < tm_to_die)
	{
		usleep(100);
		tm_now = ft_tm_passed(&(philo->data->tm_launch));
		if (ft_check_philo_dead(philo))
			return ;
	}
}

long int	ft_tm_passed(struct timeval *tm_launch)
{
	unsigned long int	tm_passed;
	struct timeval		tm_now;

	gettimeofday(&tm_now, 0);
	printf(RESET);
	tm_passed = (unsigned long int)(((tm_now.tv_sec - tm_launch->tv_sec) * 1000) + 
		((tm_now.tv_usec - tm_launch->tv_usec) / 1000));
	return ((long int)tm_passed);
}

void	ft_tm_of_launch(struct timeval *tm)
{
	gettimeofday(tm, 0);
}
