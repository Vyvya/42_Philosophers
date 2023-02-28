/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:35:22 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/28 16:38:37 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_unlock_forks(pthread_mutex_t *r_fork, pthread_mutex_t *l_fork)
{
	if (r_fork)
		pthread_mutex_unlock(r_fork);
	if (l_fork)
		pthread_mutex_unlock(l_fork);
	return (1);
}

/*every time philo takes r_fork in ft_lock_forks,
he checks d'abord if philo is died
1. lock died mutex
2. if philo_dead is set to 1: unlock died mutex, return 1
3. otherwise, return 0*/
int	ft_check_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->data->status_died_mutex);
	if (philo->data->philo_dead == 1)
	{
		pthread_mutex_unlock(philo->data->status_died_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->data->status_died_mutex);
	return (0);
}

/*lock the left and right forks to avoid deadlock:
check if num of philosophers is odd, lock right than left fork
philos even number?: lock right than left

int pthread_mutex_lock(pthread_mutex_t *mutex)
             Lock a mutex and block until it becomes available.
int pthread_mutex_unlock(pthread_mutex_t *mutex)
             Unlock a mutex.*/
static int	ft_lock_forks(t_philo *philo)
{
	if (philo->philo_index % 2 == 1)
	{
		pthread_mutex_lock(philo->r_fork_mutex);
		// printf(ORANGE);
		ft_print_msg(ft_tm_passed(&(philo->data->tm_launch)), philo, ORANGE "took right fork | \n" RESET);
		if (ft_check_philo_dead(philo) || philo->l_fork_mutex == 0)
			return (ft_unlock_forks(philo->r_fork_mutex, 0));
		pthread_mutex_lock(philo->l_fork_mutex);
		// printf(WHITE);
		ft_print_msg(ft_tm_passed(&(philo->data->tm_launch)), philo, OLIVE "took left  fork |\n" RESET);
		if (ft_check_philo_dead(philo))
			return (ft_unlock_forks(philo->r_fork_mutex, philo->l_fork_mutex));	
	}
	else
	{
		pthread_mutex_lock(philo->l_fork_mutex);
		ft_print_msg(ft_tm_passed(&(philo->data->tm_launch)), philo, OLIVE "took left  fork |\n" RESET);
		if (ft_check_philo_dead(philo))
		{
			return (ft_unlock_forks(philo->l_fork_mutex, 0));
		}
			
		pthread_mutex_lock(philo->r_fork_mutex);
		ft_print_msg(ft_tm_passed(&(philo->data->tm_launch)), philo, ORANGE "took right fork |\n" RESET);
		if (ft_check_philo_dead(philo))
			return (ft_unlock_forks(philo->l_fork_mutex, philo->r_fork_mutex));
	}		
	return (0);
}

/*Philo starts eating
check the time of the start eating process
lock left and right forks and eat


*/
int	ft_philo_eating(t_philo *philo)
{
	long int	tm_start_meal;

	if (ft_lock_forks(philo))
		return (1);
	tm_start_meal = ft_tm_passed(&(philo->data->tm_launch));
	pthread_mutex_lock(philo->philo_status_mutex);
	philo->tm_last_meal = tm_start_meal;
	pthread_mutex_unlock(philo->philo_status_mutex);
	ft_print_msg(tm_start_meal, philo, BLUE "is eating ||\n" RESET);
	ft_mysleep(philo, philo->data->tm_to_eat);
	ft_unlock_forks(philo->r_fork_mutex, philo->l_fork_mutex);
	return (0);
}
