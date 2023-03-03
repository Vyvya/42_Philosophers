/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:35:22 by vgejno            #+#    #+#             */
/*   Updated: 2023/03/01 21:10:28 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*simu(void *args)
{
	t_philo	*ph;
	int		i;

	ph = args;
	i = ph->max_meals;
	while (1)
	{
		if (ft_philo_eating(ph))
			return (0);
		if (--i == 0)
		{
			pthread_mutex_lock(ph->ph_status_mutex);
			ph->max_meals = 0;
			pthread_mutex_unlock(ph->ph_status_mutex);
		}
		if (ft_philo_sleeping(ph))
			return (0);
		ft_philo_thinking(ph);
	}
	return (0);
}

int	ft_philo_threads(t_data *data, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_create(&(((*philos)[i]).ph_id), 0, &simu, &((*philos)[i])))
		{
			ft_error ("Error malloc philo\n");
			return (1);
		}		
	}
	return (0);
}
