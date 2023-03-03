/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:01 by vgejno            #+#    #+#             */
/*   Updated: 2023/03/02 15:02:09 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline int	ft_fill_struct_philo(t_philo *philo, t_data *data, int i)
{
	philo->ph_index = i + 1;
	philo->tm_last_meal = 0;
	philo->max_meals = data->n_must_eat;
	philo->data = data;
	philo->r_fork_mutex = create_mutex();
	if (philo->r_fork_mutex == 0)
		return (2);
	philo->ph_status_mutex = create_mutex();
	if (philo->ph_status_mutex == 0)
		return (2);
	return (0);
}

static int	ft_init_philos(t_data *data, t_philo **philos)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * data->n_philos);
	if (*philos == 0)
	{
		ft_error("Error malloc philo");
		return (2);
	}	
	i = -1;
	while (++i < data->n_philos)
	{
		if (ft_fill_struct_philo(&((*philos)[i]), data, i))
		{
			ft_error("Error fill struct philo\n");
			return (2);
		}	
		if (i != 0)
			((*philos)[i].l_fork_mutex = ((*philos)[i - 1]).r_fork_mutex);
	}
	if (i == 1)
		((*philos)[0]).l_fork_mutex = 0;
	else
		((*philos)[0]).l_fork_mutex = ((*philos)[i - 1]).r_fork_mutex;
	return (0);
}

int	ft_init(t_data *data, t_philo **philos)
{
	if (ft_init_philos(data, philos))
		return (2);
	data->philo_dead = 0;
	data->died_mutex = create_mutex();
	if (data->died_mutex == 0)
		return (2);
	data->print_mutex = create_mutex();
	if (data->print_mutex == 0)
		return (2);
	ft_tm_of_launch(&(data->tm_launch));
	ft_philo_threads(data, philos);
	ft_monitor_thread(data, *philos);
	return (0);
}
