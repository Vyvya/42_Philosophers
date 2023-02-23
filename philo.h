/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:37 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/23 19:25:59 by vgejno           ###   ########.fr       */
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
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	int				num_forks;
	int				ntime_must_eat;
	int				philo_dead;
	pthread_t		monitor_id;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*status_died_mutex;
	struct timeval	tm;
	// long int		curr_tm;
	// long int		tm_launch;
	// long int		test_ms;
}	t_data;

typedef struct s_philo
{
	pthread_t		philo_id;
	pthread_mutex_t	*l_fork_mutex;
	pthread_mutex_t	*r_fork_mutex;
	pthread_mutex_t	*philo_status_mutex;
	int				philo_index;
	// int				count;
	int				max_meals;
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

int				ft_error(char *str);
int				ft_parse_init(t_data *laws, char **argv);
long int		ft_philo_atoi(char *str);
int				ft_init_philos(t_data *data, t_philo	**philo);
int				ft_init_monitor(t_data *data, t_philo *philo);

void			ft_time_of_launch(struct timeval *tm);
long int		ft_get_actual_time(void);
void			my_usleep_ms(long int millisecond);
long int		ft_time_passed(long int start, long int end);

pthread_mutex_t	*create_mutex(void);

void			*simulation(void *args);

int				ft_philo_eating(t_philo *philo);

void			ft_print_msg(long int timestamp, t_philo *philo, char *msg);

// void			ft_putstr(char *str);
// void			ft_putnbr(int num);
// void			ft_putchar(char c);

#endif
