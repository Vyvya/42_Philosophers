/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:00:30 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/14 18:27:19 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Calculate elapsed time: substract the 'struct timeval' values process_start
and time_now, storing the result in long int.
using gettimeoftheday() get actual time*/

/*Convert seconds and microseconds in milliseconds:

* Multiply secondes with *1000
* Divide microseconds with /1000
* Add the 2 values, when they are on the same scale*/

// long int	get_time_now(void)
// {
// 	long int		time;
// 	long int		second;
// 	long int		microsecond;
// 	struct timeval	curr_time;

// 	gettimeofday(&curr_time, NULL);
// 	second = second_to_milisecond(curr_time.tv_sec);
	
	
// }

// long int	ft_get_actual_time(void)
// {
// 	t_data *laws;
// 	long int	time;
// 	long int	second;
// 	long int	microsecond;
// 	struct timeval	tm;
		
// 	gettimeofday(&tm, NULL);
// 	second = tm.tv_sec * 1000;
// 	microsecond = tm.tv_usec / 1000;
// 	time = second + microsecond;
// 	printf("actual time since 01.01.1970 in ms: %ldms\n", time);
// 	return (time);
// }

long int	ft_get_actual_time(void)
{
	long int	time;
	struct timeval	tm;
		
	gettimeofday(&tm, NULL);
	time = tm.tv_sec * 1000 + tm.tv_usec / 1000;
	printf("actual time since 01.01.1970 in ms: %ldms\n", time);
	return (time);
}

void	my_usleep_ms(long int millisecond)
{
	long int	start_tm;
	long int	timer_ms;
	
	start_tm = ft_get_actual_time();
	timer_ms = ft_time_passed(start_tm, ft_get_actual_time());
	printf ("timer_ms: %ldms\n", timer_ms);
}

long int	ft_time_passed(long int start, long int end)
{
	return (end - start);
}