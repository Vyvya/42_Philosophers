/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:27 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/12 22:11:52 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time_now(void)
{
	long int		time;
	long int		second;
	long int		microsecond;
	struct timeval	time_now;

	gettimeofday(&time_now, NULL);
}
