/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking_sleeping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:35:45 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/28 16:46:04 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_thinking(t_philo *philo)
{
	ft_print_msg(ft_tm_passed(&(philo->data->tm_launch)), philo, MAGENTA "is thinking\n" RESET);
}

int	ft_philo_sleeping(t_philo *philo)
{
	unsigned long int	start_tm;
	unsigned long int	tm_now;

	// printf(PURPLE "Philo entered into sleeping loop\n");
	start_tm = ft_tm_passed(&(philo->data->tm_launch));
	// printf("start_tm: %ldms\n\n", start_tm);
	tm_now = start_tm;
	ft_print_msg(start_tm, philo, LIME "is sleeping\n" RESET);
	while (tm_now - start_tm < philo->data->tm_to_sleep)
	{
		usleep(100);
		tm_now = ft_tm_passed(&(philo->data->tm_launch));
		if (ft_check_philo_dead(philo))
			return (1);
	}
	return (0);
}