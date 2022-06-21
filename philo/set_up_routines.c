/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:35:36 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/21 12:40:38 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/*
	The first thing that will happen is indeterminate philos (threads) will take two forks for each.
	we suppose that each one takes his fork and his neighbor fork, so the forks are kinda the shared ressources
	between these threads, given this and knowing that there are as many forks as philos we should handle
	#define LEFT (i + N - 1) % N    // number of i's left neighbor
	#define RIGHT (i + 1) % N     // number of i's right neighbor


	let's say we have N = 5
	philo -> left forks[i] = forks[0]
		  -> right forks[(i + 1) % 5] = forks[1]
	philo -> left forks[i] = forks[1]
		  -> right forks[(i + 1) % 5] = forks[2]
	philo -> left forks[i] = forks[2]
		  -> right forks[(i + 1) % 5] = forks[3]
	philo -> left forks[i] = forks[3]
		  -> right forks[(i + 1) % 5] = forks[4]
	philo -> left forks[i] = forks[4]
		  -> right forks[(i + 1) % 5] = forks[0] 
*/
/*
	Instead of passing the properties of philo as a parameter
	like eating_routine(t_mutex *forks, int id, long start_time)
	we can pass the whole struct and then extract from it the props
*/
void	eating_routine(t_philo *ph)
{
	int		left;
	int		right;
	long	e_s_time;

	left = ph->id;
	right = (ph->id + 1) % ph->n_philos;
	pthread_mutex_lock(&ph->forks[left]); // CHECK THE ACCURACY OF THIS
	printf("%ld %d has taken a his left fork\n", get_time(ph->init_time), ph->id);
	pthread_mutex_lock(&ph->forks[right]);
	printf("%ld %d has taken a his right fork\n", get_time(ph->init_time), ph->id);
	printf("%ld %d is eating\n");
	e_s_time = get_time(0);
	while (get_time(0) - e_s_time < ph->t_eat)
		usleep(75);
	pthread_mutex_unlock(&ph->forks[left]);
	pthread_mutex_unlock(&ph->forks[right]);
}

void	*set_up_routines(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		eating_routine(philo);
		sleeping_routine(philo);
		thinking_routine(philo);
	}
	return (NULL);
}


