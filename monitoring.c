/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:25:01 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/23 19:18:22 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//check if one of philos has died
static void	ft_monitoring(void *args)
{
	printf("Monitoring");
}

//create pthread monitor
int	ft_init_monitor(t_data *data, t_philo *philo)
{
	if (pthread_create(&(data->monitor_id), 0, &ft_monitoring, philo))
	{
		return (ft_error("Error monitor pthread"));
	}
	return (0);
}
