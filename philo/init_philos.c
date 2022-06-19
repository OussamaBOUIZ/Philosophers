/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:14:02 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/19 19:40:35 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// pthread_t	*create_philos(t_arg *args)
// {
// 	pthread_t	*philos;
// 	int			i;

// 	philos = malloc(sizeof(pthread_t) * args->philo);
// 	if (!philos)
// 			malloc_fail();
// 	i = -1;
// 	while (++i < args->philo)
// 	{
// 		str.ph_id = i + 1;
// 		if (pthread_create(&philos[i], NULL, set_up_routines, (void	*)args))
// 			pthr_creat_fail();
// 	}
// 	return (philos);
// }

/*

pthread_t	*create_philos(t_arg *prop)
{
	pthread_t	*philos;
	int			i;

	philos = malloc(sizeof(pthread_t) * prop->philo);
	if (!philos)
			malloc_fail();
	
	i = -1;
	while (++i < prop->philo)
	{
		str.ph_id = i + 1;
		if (pthread_create(&philos[i], NULL, set_up_routines, (void *){prop, i}))
			pthr_creat_fail();
	}
	return (philos);
}
*/

t_mutex	*create_forks(t_arg	*args)
{
	t_mutex	*forks;
	int		i;

	forks = malloc(sizeof(t_mutex) * args->philo);
	if (!forks)
		malloc_fail();
	i = -1;
	while (++i < args->philo)
		if (pthread_mutex_init(&forks[i], NULL))
			pthr_fail();
	return (forks);
}


/*
	pthread_mutex_lock(&lock);
	is_eating(timestamp, ID);
	pthread_mutex_unlock(&lock);
	is_sleeping(timestamp, args->time_to_sleep);
	is_thinking(timestamp, args->time_to_die);

	is_thinking(., .)
	{
		while (args->time_to_die)
		{
			
		}
	}
*/
