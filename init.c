/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:01 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/28 17:09:09 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//create a mutex_ptr
static pthread_mutex_t	*create_mutex(void)
{
	pthread_mutex_t	*mutex_ptr;

	mutex_ptr = malloc(sizeof(pthread_mutex_t) * 1);
	if (mutex_ptr == 0)
	{
		ft_error("Error malloc mutex\n");
		return (0);
	}
	pthread_mutex_init(mutex_ptr, 0);
	return (mutex_ptr);
}

static inline int	ft_fill_struct_philo(t_philo *philo, t_data *data, int i)
{
	philo->philo_index = i + 1;
	philo->tm_last_meal = 0;
	philo->max_meals = data->n_must_eat;
	philo->data = data;
	philo->r_fork_mutex = create_mutex();
	if (philo->r_fork_mutex == 0)
		return (2);
	philo->philo_status_mutex = create_mutex();
	if (philo->philo_status_mutex == 0)
		return (2);
	return (0);
}

/*init struct philo for each philo and create threads
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)
Creates a new thread of execution.
int pthread_join(pthread_t thread, void **value_ptr)
Causes the calling thread to wait for the termination of the specified thread.*/
	
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
	if (i == 1) //if there is only 1 philo
		((*philos)[0]).l_fork_mutex = 0;
	else
		((*philos)[0]).l_fork_mutex = ((*philos)[i - 1]).r_fork_mutex;
	return (0);
}

int	ft_init(t_data *data, t_philo **philos)
{
	int	i;
	
	if(ft_init_philos(data, philos))
		return (2);
	data->died_mutex = create_mutex();
	if (data->died_mutex == 0)
		return (2);
	data->print_mutex = create_mutex();
	if (data->print_mutex == 0)
		return (2);
	data->philo_dead = 0;
	i = -1;
	ft_tm_of_launch(&(data->tm_launch));
	while (++i < data->n_philos)
	{
		if (pthread_create(&(((*philos)[i]).philo_id), 0, &simu, &((*philos)[i])))
		{
			ft_error ("Error malloc philo\n");
			return (1);
		}		
	}
	ft_init_monitor(data, *philos);	
	return (0);
}
