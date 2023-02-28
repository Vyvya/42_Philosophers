/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:25:01 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/28 16:46:47 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_print_msg_died(long int time, t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->data->status_died_mutex);
	if (philo->data->philo_dead == 1)
	{
		pthread_mutex_unlock(philo->data->status_died_mutex);
		return ;
	}
	else
	{
		philo->data->philo_dead = 1;
		pthread_mutex_unlock(philo->data->status_died_mutex);
		pthread_mutex_lock(philo->data->print_mutex);
		// ft_print_msg(ft_tm_passed(&(philo->data->tm_launch)), philo, msg);
		ft_putnbr_fd(time, 1);
		ft_putstr_fd(" ", 1);
		ft_putnbr_fd(philo->philo_index, 1);
		ft_putstr_fd(msg, 1);
		pthread_mutex_unlock(philo->data->print_mutex);
	}
}

static long int	mon_check_philo_dead(t_philo *philos)
{
	long int	tm_now;
	int			i;

	i = -1;
	while (++i < philos->data->n_philos)
	{
		// printf("philos->data->num_philos]: %d\n", philos->data->num_philos);
		tm_now = ft_tm_passed(&(philos[i].data->tm_launch));
		pthread_mutex_lock(philos[i].philo_status_mutex);
		// printf("philos[i].start_last_meal: %ldms\n\n", philos[i].start_last_meal);
		// printf("philos[i].data->time_to_die: %ldms\n\n", philos[i].data->time_to_die);
		if (tm_now - philos[i].tm_last_meal > philos[i].data->tm_to_die)
		{
			pthread_mutex_unlock(philos[i].philo_status_mutex);
			ft_print_msg(tm_now, &(philos[i]), RED "has died\n" RESET);
			return (1);
		}
		pthread_mutex_unlock(philos[i].philo_status_mutex);
	}
	return (0);
}

static long int	mon_simulation_finish(t_philo *all_philos)
{
	int		i;

	i = -1;
	while (++i < all_philos->data->n_philos)
	{
		pthread_mutex_lock(all_philos[i].philo_status_mutex);
		if (all_philos[i].max_meals == -1 || all_philos[i].max_meals > 0)
		{
			pthread_mutex_unlock(all_philos[i].philo_status_mutex);
			return (0);
		}
		pthread_mutex_unlock(all_philos[i].philo_status_mutex);
	}
	ft_print_msg_died(ft_tm_passed(&(all_philos->data->tm_launch)), all_philos, " DIED\n");
		return (-1);
	return (1);
}
//check if one of philos has died
static void	*ft_monitoring(void *args)
{
	t_philo	*philos;

	philos = args;
	while (1)
	{
		if (mon_check_philo_dead(philos))
			return (0);
		if (mon_simulation_finish(philos))
			return (0);
		usleep(100);	
	}
	return (0);
}

//create pthread monitor
int	ft_init_monitor(t_data *data, t_philo *philos)
{
	if (pthread_create(&(data->monitor_id), 0, &ft_monitoring, philos))
	{
		ft_error("Error monitor pthread");
		return (1);
	}
	// printf(YELLOW "Monitor OK!\n" RESET);
	return (0);
}
