/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:25:01 by vgejno            #+#    #+#             */
/*   Updated: 2023/03/02 17:25:15 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_print_msg_died(long int time, t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->data->died_mutex);
	if (philo->data->philo_dead == 1)
	{
		pthread_mutex_unlock(philo->data->died_mutex);
		return ;
	}
	else
	{
		philo->data->philo_dead = 1;
		pthread_mutex_unlock(philo->data->died_mutex);
		pthread_mutex_lock(philo->data->print_mutex);
		printf("time[%0.3ldms] philo[%d] %s", time, philo->ph_index, msg);
		pthread_mutex_unlock(philo->data->print_mutex);
	}
}

static int	ft_monitor_check_phdeath(t_philo *philos)
{
	long int	tm_now;
	int			i;

	i = -1;
	while (++i < philos->data->n_philos)
	{
		tm_now = get_tm(&(philos[i].data->tm_launch));
		pthread_mutex_lock(philos[i].ph_status_mutex);
		if (tm_now - philos[i].tm_last_meal > philos[i].data->tm_to_die)
		{
			pthread_mutex_unlock(philos[i].ph_status_mutex);
			ft_print_msg_died(tm_now, &(philos[i]), R "has died    ❌\n" RS);
			return (1);
		}
		pthread_mutex_unlock(philos[i].ph_status_mutex);
	}
	return (0);
}

static int	ft_monitor_simu_end(t_philo *all_philos)
{
	int		i;

	i = -1;
	while (++i < all_philos->data->n_philos)
	{
		pthread_mutex_lock(all_philos[i].ph_status_mutex);
		if (all_philos[i].max_meals == -1 || all_philos[i].max_meals > 0)
		{
			pthread_mutex_unlock(all_philos[i].ph_status_mutex);
			return (0);
		}
		pthread_mutex_unlock(all_philos[i].ph_status_mutex);
	}
	ft_print_msg_died(get_tm(&(all_philos->data->tm_launch)),
		all_philos, YELLOW "simulation end\n" RS);
	return (1);
}

static void	*ft_monitor(void *args)
{
	t_philo	*philos;

	philos = args;
	while (1)
	{
		if (ft_monitor_check_phdeath(philos))
			return (0);
		if (ft_monitor_simu_end(philos))
			return (0);
		usleep(100);
	}
	return (0);
}

int	ft_monitor_thread(t_data *data, t_philo *philos)
{
	if (pthread_create(&(data->monitor_id), 0, &ft_monitor, philos))
	{
		ft_error("Error monitor pthread");
		return (1);
	}
	return (0);
}
