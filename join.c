/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:18:38 by vgejno            #+#    #+#             */
/*   Updated: 2023/03/01 12:50:32 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_join_threads(int num_philos, t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_join(philos[i++].ph_id, 0))
		{
			ft_error("Error joining threads\n");
			return (1);
		}
	}
	if (pthread_join(data->monitor_id, 0))
	{
		ft_error("Error joining threads\n");
		return (1);
	}
	return (0);
}
