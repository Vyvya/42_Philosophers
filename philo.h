/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:37 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/16 17:51:56 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

# define S_TAKE_FORK "has taken a fork\n"
# define S_DROP_FORK "has dropped a fork\n"
# define S_EAT "is eating\n"
# define S_THINK "is thinking\n"
# define S_SLEEP "is sleeping\n"
# define S_DEAD "died\n"

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_forks;
	int				ntime_must_eat;
	pthread_t		monitor;
	pthread_mutex_t	*msg_print;
	pthread_mutex_t	*msg_died;
	struct timeval	tm;
	long int		curr_tm;
	long int		start_tm;
	long int		test_ms;
}	t_data;

typedef struct s_philo
{
	pthread_t		philo_thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*philo_auto_check;
	int				philo_index;
	int				count;
	long int		start_last_meal;
	t_data			*data;
}	t_philo;

// typedef struct s_time
// {
// 	struct timeval	tm;
// 	long int		time;
// 	int				tm_eat;
// 	int				tm_sleep;
// 	int				tm_die;
// }t_time;

int	ft_error(char *str);
int	ft_check_parse(t_data *laws, char **argv);
int	ft_philo_atoi(char *str);
long int	ft_get_actual_time(void);
void	my_usleep_ms(long int millisecond);
long int	ft_time_passed(long int start, long int end);
int	ft_init_philo(t_data data, t_philo	*philo);

#endif