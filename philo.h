/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:37 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/28 17:09:30 by vgejno           ###   ########.fr       */
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

# define WHITE      "\033[38;2;255;255;255m"
# define BLACK      "\033[38;2;0;0;0m"
# define RED        "\033[38;2;255;0;0m"
# define LIME       "\033[38;2;0;255;0m"
# define BLUE       "\033[38;2;0;80;255m"
# define YELLOW     "\033[38;2;255;255;0m"
# define GCYAN      "\033[38;2;0;164;114m"
# define MAGENTA    "\033[38;2;255;0;255m"
# define SILVER     "\033[38;2;192;192;192m"
# define GRAY       "\033[38;2;128;128;128m"
# define MAROON     "\033[38;2;128;0;0m"
# define OLIVE      "\033[38;2;128;128;0m"
# define GREEN      "\033[38;2;0;128;0m"
# define PURPLE     "\033[38;2;128;0;128m"
# define TEAL       "\033[38;2;0;128;128m"
# define NAVY       "\033[38;2;0;0;128m"
# define DB         "\033[38;2;0;0;139m"
# define LC         "\033[38;2;224;255;255m"
# define MBLUE      "\033[38;2;58;62;92m"
# define LBLUE      "\033[38;2;114;121;179m"
# define GGREEN     "\033[38;2;14;195;6m"
# define ORANGE		"\033[38;5;208m"

# define RESET      "\033[0m"

typedef struct s_data
{
	int				n_philos;
	long int		tm_to_die;
	long int		tm_to_eat;
	long int		tm_to_sleep;
	int				n_forks;
	int				n_must_eat;
	int				philo_dead;
	pthread_t		monitor_id;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*died_mutex;
	struct timeval	tm_launch;
	// long int		curr_tm;
	// long int		tm_launch_int;
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
	long int		tm_last_meal;
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

void			ft_error(char *str);
int				ft_parse(t_data *laws, char **argv, int argc);
long int		ft_philo_atoi(char *str);
int				ft_init(t_data *data, t_philo **philos);
int				ft_init_monitor(t_data *data, t_philo *philo);

void			ft_tm_of_launch(struct timeval *tm);
long int		ft_get_actual_time(void);
void			ft_mysleep(t_philo *philo, long int tm_to_die);
long int		ft_tm_passed(struct timeval *tm_launch);

// pthread_mutex_t	*create_mutex(void);

void			*simu(void *args);

int				ft_philo_eating(t_philo *philo);
void			ft_philo_thinking(t_philo *philo);
int				ft_philo_sleeping(t_philo *philo);
int				ft_check_philo_dead(t_philo *philo);

int				ft_join_threads(int n_philos, t_philo *philos, t_data *data);
void			ft_destroy_free_threads(t_data *data, t_philo *philos);

void			ft_print_msg(long int tm_stamp, t_philo *philo, char *msg);

void			ft_putstr_fd(char *str, int fd);
void			ft_putnbr(int num);
void	ft_putnbr_fd(int number, int fd);
// void			ft_putchar(char c);

#endif
