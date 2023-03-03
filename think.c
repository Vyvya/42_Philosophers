/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:35:45 by vgejno            #+#    #+#             */
/*   Updated: 2023/03/02 15:04:10 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_thinking(t_philo *philo)
{
	msg(get_tm(&(philo->data->tm_launch)), philo,
		MAGENTA "is thinking 🔮\n" RS);
}
