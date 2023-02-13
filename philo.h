/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:37 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/12 22:11:45 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int	num_philos;
	int	num_forks;
	int	tm_eat; /*in ms, needs to keep his 2 forks all that time*/
	int	tm_sleep; //in ms
	int	tm_die; /*if a philosopher doesn’t start eating ’time_to_die’
		milliseconds after starting his last meal or the beginning of the 
		simulation, it dies*/
	int	ntm_phil_must_eat; /*optional, if all philosophers eat at least 
	’number_of_times_each_philosopher_must_eat’ the simulation will stop. 
	If not specified, the simulation will stop only at the death of a philosopher*/
} t_philo;

struct timeval
{
	time_t		tv_sec; //Num of seconds elapsed from 01.01.1970
	long int	tv_usec; /*Num of microseconds passed after the num of seconds
						 from 01.01.1970, for greater precision*/
};

#endif