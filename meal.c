/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:35:22 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/23 19:25:09 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*lock the left and right forks
to avoid deadlock:
check if num of philosophers is odd, lock right than left fork
even number: lock left than right

int pthread_mutex_lock(pthread_mutex_t *mutex)
             Lock a mutex and block until it becomes available.
int pthread_mutex_unlock(pthread_mutex_t *mutex)
             Unlock a mutex.*/
static int	ft_lock_forks(t_philo *philo)
{
	if (philo->philo_index % 2 != 0)
	{
		pthread_mutex_lock(philo->r_fork_mutex);
		ft_print_msg(100, philo, "took right fork");
	}
	return (0);
}

/*Philo in the process of eating
lock left and right forks
check the time of the start eating process

*/
int	ft_philo_eating(t_philo *philo)
{
	int	tm_start_meal;

	if (ft_lock_forks(philo))
		return (1);
	return (0);	
}

/*void	*routine(void *)
{
	t_philo	the_philo;
	
	pthread_mutex_init(&the_philo.l_fork, NULL);
	pthread_mutex_init(&the_philo.r_fork, NULL);
	
	pthread_mutex_lock(&the_philo.l_fork);
	pthread_mutex_unlock(&the_philo.l_fork);

	pthread_mutex_lock(&the_philo.r_fork);
	pthread_mutex_unlock(&the_philo.r_fork);
	
	pthread_mutex_destroy(&the_philo.l_fork);
	pthread_mutex_destroy(&the_philo.r_fork);
}*/