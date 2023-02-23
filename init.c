/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:01 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/21 15:40:26 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static int	ft_fill_struct_philo(t_data *data, t_philo *philo, int i)
// {
// 	philo->philo_index = i + 1;
// 	philo->start_last_meal = 0;
// 	philo->max_meals = data->ntime_must_eat;
// 	philo->data = data;
// 	philo->r_fork = create_mutex();
// 	philo->philo_auto_check = create_mutex();
// 	if (philo->r_fork == 0 || philo->philo_auto_check == 0)
// 		return (2);
// 	return (0);
// }

// //init struct philo for each philo and create threads

// int	ft_init_philos(t_data *data, t_philo **philo)
// {
// 	int	i;

// 	i = -1;
// 	//malloc num_philos structs of philo
// 	*philo = malloc(sizeof(t_philo) * data->num_philos);
// 	if (!*philo)
// 		return (ft_error("Error malloc philo"));
// 	//fill structs
// 	while (++i < data->num_philos)
// 	{
// 		if (ft_fill_struct_philo(data, &((*philo)[i]), i))
// 			return (ft_error("Error fill struct philo"));
// 		if (i != 0)
// 			((*philo)[i].l_fork = ((*philo)[i - 1]).r_fork);	
// 	}
// 	if (i == 1)
// 		((*philo)[0]).l_fork = 0;
// 	else
// 		((*philo)[0]).l_fork = ((*philo)[i - 1]).r_fork;
// 	ft_time_of_launch(&(data->tm));
// 	i = -1;
// 	while (++i < data->num_philos)
// 	{
// 		if (pthread_create(&(((*philo)[i]).philo_thread), 0, &simulation, &((*philo)[i])))
// 			return (ft_error("Error malloc philo"));
// 	}
// 	ft_init_monitor(data, *philo);
// 	return (0);
// }

/*while (data. > philo->philo_index)
	{
		if (pthread_create(&philo->philo_thread[data.num_philos], NULL, &ft_philo_eating, NULL))
			return (-1);
		data.num_philos--;	
	}
	
	if (pthread_create(&data.monitor, NULL, &ft_monitoring, NULL))
		return (-1);*/

// static int	ft_init_data(t_data *data, t_philo **philo)
// {
// 	data->msg_print = create_mutex();
// 	data->msg_died = create_mutex();
// 	if (data->msg_print == 0 || data->msg_died == 0)
// 		return (2);
// 	data->died = 0;
// 	ft_time_start(&(data->tm));
// 	return (0);
// }

