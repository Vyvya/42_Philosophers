/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:35:22 by vgejno            #+#    #+#             */
/*   Updated: 2023/03/02 15:04:15 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_unlock_forks(pthread_mutex_t *a, pthread_mutex_t *b)
{
	if (a)
		pthread_mutex_unlock(a);
	if (b)
		pthread_mutex_unlock(b);
	return (1);
}

int	ft_check_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->data->died_mutex);
	if (philo->data->philo_dead == 1)
	{
		pthread_mutex_unlock(philo->data->died_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->data->died_mutex);
	return (0);
}

static int	ft_lock_forks(t_philo *philo)
{
	if (philo->ph_index % 2 == 1)
	{
		pthread_mutex_lock(philo->r_fork_mutex);
		msg(get_tm(&(philo->data->tm_launch)), philo, OR "took r_fork 🥢\n" RS);
		if (ft_check_philo_dead(philo) || philo->l_fork_mutex == 0)
			return (ft_unlock_forks(philo->r_fork_mutex, 0));
		pthread_mutex_lock(philo->l_fork_mutex);
		msg(get_tm(&(philo->data->tm_launch)), philo, OL "took l_fork 🥢\n" RS);
		if (ft_check_philo_dead(philo))
			return (ft_unlock_forks(philo->r_fork_mutex, philo->l_fork_mutex));
	}
	else
	{
		pthread_mutex_lock(philo->l_fork_mutex);
		msg(get_tm(&(philo->data->tm_launch)), philo, OL "took l_fork 🥢\n" RS);
		if (ft_check_philo_dead(philo))
			return (ft_unlock_forks(philo->l_fork_mutex, 0));
		pthread_mutex_lock(philo->r_fork_mutex);
		msg(get_tm(&(philo->data->tm_launch)), philo, OR "took r_fork 🥢\n" RS);
		if (ft_check_philo_dead(philo))
			return (ft_unlock_forks(philo->l_fork_mutex, philo->r_fork_mutex));
	}		
	return (0);
}

int	ft_philo_eating(t_philo *philo)
{
	long int	tm_start_meal;

	if (ft_lock_forks(philo))
		return (1);
	tm_start_meal = get_tm(&(philo->data->tm_launch));
	pthread_mutex_lock(philo->ph_status_mutex);
	philo->tm_last_meal = tm_start_meal;
	pthread_mutex_unlock(philo->ph_status_mutex);
	msg(tm_start_meal, philo, LIME "is eating   🍜\n" RS);
	ft_mysleep(philo, philo->data->tm_to_eat);
	ft_unlock_forks(philo->r_fork_mutex, philo->l_fork_mutex);
	return (0);
}
