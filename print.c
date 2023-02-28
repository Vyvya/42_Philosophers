/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:35:22 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/27 19:33:47 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*to print the message the printing operation has to be locked
printing meassage: time in milliseconds philo[num] is [action]*/
// void	ft_print_msg(long int timestamp, t_philo *philo, char *msg)
// {
// 	pthread_mutex_lock(philo->data->print_mutex);
// 	pthread_mutex_lock(philo->data->status_died_mutex);
// 	if (philo->data->philo_dead == 0)
// 	{
// 		pthread_mutex_unlock(philo->data->status_died_mutex);
// 		ft_putnbr(timestamp);
// 		ft_putstr_fd(" Philo", 2);
// 		ft_putnbr(philo->philo_index);
// 		ft_putstr_fd(msg, 2);
// 	}
// 	else
// 		pthread_mutex_unlock(philo->data->status_died_mutex);
// 	pthread_mutex_unlock(philo->data->print_mutex);
// }

void	ft_print_msg(long int timestamp, t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->data->print_mutex);
	pthread_mutex_lock(philo->data->status_died_mutex);
	if (philo->data->philo_dead == 0) //philo not dead
	{
		pthread_mutex_unlock(philo->data->status_died_mutex);
		printf("time[%ldms] philo[%d] %s", timestamp, philo->philo_index, msg);
	}
	else
		pthread_mutex_unlock(philo->data->status_died_mutex);
	pthread_mutex_unlock(philo->data->print_mutex);
}