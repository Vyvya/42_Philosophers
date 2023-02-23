/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:13 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/23 19:15:20 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_philo_pthreads(t_data *data, t_philo **philo)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_create(&(((*philo)[i]).philo_id), 0, &simulation, &((*philo)[i])))
			return (ft_error("Error malloc philo"));
	}
	return (0);
}

static int	ft_fill_struct_philo(t_data *data, t_philo *philo, int i)
{
	philo->philo_index = i + 1;
	philo->start_last_meal = 0;
	philo->max_meals = data->ntime_must_eat;
	philo->data = data;
	philo->l_fork_mutex = create_mutex();
	philo->r_fork_mutex = create_mutex();
	philo->philo_status_mutex = create_mutex();
	if (philo->r_fork_mutex == 0 || philo->philo_status_mutex == 0)
		return (2);
	return (0);
}

/*init struct philo for each philo and create threads
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)
	Creates a new thread of execution.
int pthread_join(pthread_t thread, void **value_ptr)
	Causes the calling thread to wait for the termination of the specified thread.*/

int	ft_init_philos(t_data *data, t_philo **philo)
{
	int	i;

	i = -1; //to save 1 line of code
	//malloc num_philos structs of philo
	*philo = malloc(sizeof(t_philo) * data->num_philos);
	if (!*philo)
		return (ft_error("Error malloc philo"));
	//fill structs of philos
	while (++i < data->num_philos)
	{
		if (ft_fill_struct_philo(data, &((*philo)[i]), i))
			return (ft_error("Error fill struct philo"));
		if (i != 0)
			((*philo)[i].l_fork_mutex = ((*philo)[i - 1]).r_fork_mutex);	
	}
	if (i == 1) //if there is only 1 philo
		((*philo)[0]).l_fork_mutex = 0;
	else
		((*philo)[0]).l_fork_mutex = ((*philo)[i - 1]).r_fork_mutex;
	ft_time_of_launch(&(data->tm));
	ft_philo_pthreads(data, philo);
	// i = -1;
	// while (++i < data->num_philos)
	// {
	// 	if (pthread_create(&(((*philo)[i]).philo_id), 0, &simulation, &((*philo)[i])))
	// 		return (ft_error("Error malloc philo"));
	// }
	ft_init_monitor(data, *philo);
	return (0);
}

int	ft_parse_init(t_data *data, char **argv)
{
	// long int	time;

	data->num_philos = ft_philo_atoi(argv[1]);
	printf("number of philos: %d\n", data->num_philos);
	data->time_to_die = ft_philo_atoi(argv[2]);
	printf("time to die: %ld\n", data->time_to_die);
	data->time_to_eat = ft_philo_atoi(argv[3]);
	printf("time to eat: %ld\n", data->time_to_eat);
	data->time_to_sleep = ft_philo_atoi(argv[4]);
	printf("time to sleep: %ld\n", data->time_to_sleep);
	if (argv[5])
	{
		data->ntime_must_eat = ft_philo_atoi(argv[5]);
		// printf("number of time each philo must eat: %d\n", data->ntime_must_eat);
		if (data->ntime_must_eat < 0)
			return (-1);
	}
	else
		data->ntime_must_eat = -1;
	if (data->num_philos <= 0 || data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
		return (-1);
	// if (ft_init_philos(&data, &philo))
	// 	return (ft_error("Error init philos"));	
	data->print_mutex = create_mutex();
	data->status_died_mutex = create_mutex();
	if (data->print_mutex == 0 || data->status_died_mutex == 0)
		return (2);
	data->philo_dead = 0;		
	return (0);
}
