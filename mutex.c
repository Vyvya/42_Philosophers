/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:22:21 by vgejno            #+#    #+#             */
/*   Updated: 2023/03/01 12:25:09 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//create a mutex_ptr
pthread_mutex_t	*create_mutex(void)
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
