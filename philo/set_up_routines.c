/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:35:36 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/20 19:14:12 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/*
	The first thing that will happen is indeterminate philos (threads) will take two forks for each.
	we suppose that each one takes his fork and his neighbor fork, so the forks are kinda the shared ressources
	between these threads, given this and knowing that there are as many forks as philos we should handle
	#define LEFT (i + N - 1) % N    // number of i's left neighbor
	#define RIGHT (i + 1) % N     // number of i's right neighbor


	let's say we have N = 7
	philo 1 will take forks[(2 + 7 - 1) % 7] = forks[1]
				 and forks[(7 + 1) % 7] = forks[1]
	philo 2 will take forks[(3 + 7 - 1) % 7] = forks[2]
				 and forks[(1 + 1) % 7] = forks[2]
*/
void	eating_routine(t_mutex *forks, int id)
{
	
	t_mutex	*right;
	t_mutex	*left;

	right = 
}

void	*set_up_routines(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	eating_routine(philo->forks, philo->id);
	sleeping_routine();
	thinking_routine();
	return (NULL);
}


