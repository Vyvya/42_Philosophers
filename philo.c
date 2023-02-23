/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:32:30 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/21 15:46:42 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*compile with -pthread?

Any change of status of a philosopher must be written as follows (with X 
replaced with the philosopher number and timestamp_in_ms the current timestamp
in milliseconds)
◦ timestamp_in_ms X has taken a fork  
◦ timestamp_in_ms X is sleeping  
◦ timestamp_in_ms X is thinking  
◦ timestamp_in_ms X died  

• The status printed should not be scrambled or intertwined with another
philosopher’s status.

• You can’t have more than 10 ms between the death of a philosopher and when it
will print its death.*/

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (ft_error("Error wrong number of arguments"));
	if (ft_parse_init(&data, argv))
		return (ft_error("Error invalid argument"));
	// if (ft_init_data(data, philo))
	// 	return (ft_error("Error init data"));
	if (ft_init_philos(&data, &philo))
		return (ft_error("Error init philos"));
	// ft_create_monitor(data, philo);
	return (0);
}
