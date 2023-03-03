/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:35:45 by vgejno            #+#    #+#             */
/*   Updated: 2023/03/02 14:31:53 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *msg)
{
	if (msg == 0)
		return ;
	printf(R "💣 %s\n", msg);
	printf(RS);
}

void	ft_destroy_free_threads(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		pthread_mutex_destroy((philos[i]).r_fork_mutex);
		free(philos[i].r_fork_mutex);
		pthread_mutex_destroy(philos[i].ph_status_mutex);
		free(philos[i].ph_status_mutex);
	}
	pthread_mutex_destroy(data->print_mutex);
	pthread_mutex_destroy(data->died_mutex);
	free(data->print_mutex);
	free(data->died_mutex);
	free(philos);
}
