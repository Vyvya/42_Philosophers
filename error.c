/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:35:45 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/28 16:45:43 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *msg)
{
	if (msg == 0)
		return ;
	ft_putstr_fd(msg, 2);
}

// int	ft_error(char *str)
// {
// 	int	len;

// 	len = 0;
// 	while (*(str + len))
// 		len++;
// 	write(2, str, len);
// 	write(2, "\n", 1);
// 	return (-1);
// }

/*int pthread_attr_destroy(pthread_attr_t *attr)
             Destroy a thread attributes object.
int pthread_mutex_destroy(pthread_mutex_t *mutex)
             Destroy a mutex.*/

void	ft_destroy_free_threads(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		pthread_mutex_destroy((philos[i]).r_fork_mutex);
		free(philos[i].r_fork_mutex);
		pthread_mutex_destroy(philos[i].philo_status_mutex);
		free(philos[i].philo_status_mutex);
	}
	pthread_mutex_destroy(data->print_mutex);
	pthread_mutex_destroy(data->status_died_mutex);
	free(data->print_mutex);
	free(data->status_died_mutex);
	free(philos);
}