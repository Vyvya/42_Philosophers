/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_theory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:11:48 by vgejno            #+#    #+#             */
/*   Updated: 2023/02/23 17:32:52 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*rules: each philo starts by taking right fork, than - left one as soon as it 
is available they wait. if each philo takes right fork by chance at the
same time, it will be deadlock situation, they will waite forever.
1 possible solution: philo takes right fork, if left one is not available,
he puts right one back on the table, waits for 10 sec, and repeats the action.
problem: if all philos take do this action by chance synchronised - deadlock.
Separate solutions for odd and even numbers of philos.
For each philo we will launch own thread, and performs in eternal cycle 
following actions:
1. take 2 forks, print to standart output that he took the forks;
2. eat, during the time given, print message;
3. put down the forks, print to stdout;
4. fall asleep during the time given, print message

Solution: let the philos to the table with a certain waiting time (that will
increase the speed of working algo) + algorithm Dijkstra
Algo not optimal, but with garanty sans deadlock:
1. if philos are numbered and forks are numbered, each philo takes first a
fork with the lower number, except one. ex. if num p = 5: 
1. p1 wants to take f1 (smallerst), and p5 wants also f1. that will break the
circle of deadlock.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct philo_data
{ 
	pthread id;
	int	time_to_die;
	int	time_to_sleep;
	int	time_to_eat;
	t_mutex *left; //or after Dijska, fork with min and max num
	t_mutex *right;
	struct timeval //int timeofday(struct timeval *, 0)
	int	must_die; //has to be also defended by mutex
};

struct timeval
{
	long	tv_sec; //time passed from a certain date chosen, time grows sec by sec 
	long	tv_usec; // time in microsecondes between seconds of tv_sec, in cadre of [0, 1000000]
	// tv_sec*1000 + tv_usec / 1000;
	//in the beginning of the program, get time of the day, stock it, and make minus
	//time of the beginnning of the program, * 1000
}

void	*philo(void *data)
{
	if (data->num % 2 == 0) //even numbered philos will come to the table with a retard
	{
		usleep(250); //speed up algo and eliminate deadlock
	}
	while (1)
	{
		if (must_died == 1)
			return (0);
		lock(left);
		printf("left fork taken"); // printf is problem, because all threads try 
		//to print on the standart stdout, we have to defend it by mutex
		lock(right);
		print("right fork taken");
		print("philo eating");
		get_time_of_day(last_time_eating); //is_died : how to know? take the time of the running process. if the time minus the time
//of the last eating of a philo is > time_to_die * 1000, he is dead..must_die == 1; return (1)

		usleep(time_to_eat * 1000);
		unlock();
		unlock();
		print("sleeping");
		usleep(time_to_sleep * 1000);
		print("thinking"); // in reality we need to get the mutex..
		//thinking when philo cannt take a fork, process of
		//sleeping is a process of waiting for the fork
	}
}


int	main(int argc, char *argv[]) // read the given param
{
	//initialise params
	//put given params in structure
	//one global mutex for all philos
	//create thread for all philos
	//save ids
	//all variables should be defendet from data race! to check for data race: flag fsanitiser
	while (i < N)
		pthread_create(&id, fr_philo(), data); //fnct imitating the work of philos
		// with a pointer to each fork;
	while (1) //endless loop
	{
		for philo in N philos, if he died, 
		if (is_died(philo)) //takes a pointer to the struct philo
		must_die == 1; //is_died : how to know? take the time of the running process. if the time minus the time
			//of the last eating of a philo is > time_to_die * 1000, he is dead..must_die == 1; return (1)
			//if all not detached, we have to join all thread, //clean all memory
			//and should destroy mutexes, malloc
			//philos should not reach destroyed threads	
			return (0); //if all threads detached
			//other option, detach the threads in the beginning and than they dont need
			//to be joined, so return (0) immediantly
	}	
}

int	n;
int	time_to_die;
int	time_to_eat;
int	time_to_sleep;

/*usleep problem: it falls asleep for longer that its value, thats because the mistake accumulates.
that's why we have to write own usleep. because the running of the usleep itself takes time, to
look for it etc. thats why philo will falsely die*/

void	my_usleep(int tm) //time, milisec
{
	struct timeval start;
	struct timeval time_now;
	getting_time_of_day(&start, 0);
	getting_time_of_day(&time_now, 0);
	//imitating sleeping for a milisecond
	while (time_now.tv_sec - start.tv_sec) + (time_now.tv_sec - start.tv_sec) / 1000 < ms)
	{
		usleep(10);
		get_time_of_day(struct timeval(&time_now, 0));
	}
}

//optimize the process! no extra copying