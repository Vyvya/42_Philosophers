/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:32:30 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/28 16:39:26 by vgejno           ###   ########.fr       */
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
will print its death.

1. check and parse arguments
2. init philos/mutexes
3. init monitoring mutex
4. start simulation/eat/sleep/think
5. check for dead/max_meals
5. destroy threads/free
*/

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philos;

	philos = 0;
	if (ft_parse(&data, argv, argc))
	{
		ft_error("Error parsing invalid argument\n");
		return (1);
	}
	if (ft_init(&data, &philos))
	{
		free(philos);
		ft_error("Error init philos meassage from main\n");
		return (2);
	}
	if (ft_join_threads(data.n_philos, philos, &data))
	{
		free(philos);
		return (3);
	}	
	ft_destroy_free_threads(&data, philos);
	return (0);
}
