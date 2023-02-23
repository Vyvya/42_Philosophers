/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:35:45 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/21 16:13:47 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	write(2, str, len);
	write(2, "\n", 1);
	return (-1);
}

/*int pthread_attr_destroy(pthread_attr_t *attr)
             Destroy a thread attributes object.
int pthread_mutex_destroy(pthread_mutex_t *mutex)
             Destroy a mutex.*/