/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:14:02 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/22 11:24:57 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_mutex	*create_forks(t_arg	*args)
{
	t_mutex	*forks;
	int		i;

	forks = malloc(sizeof(t_mutex) * args->philo);
	if (!forks)
		return ((t_mutex *)malloc_fail());
	i = -1;
	while (++i < args->philo)
		if (pthread_mutex_init(&forks[i], NULL))
			return ((t_mutex *)pthr_fail());
	return (forks);
}

t_philo	**get_philos_prop(t_arg	*args, t_mutex *forks)
{
	t_philo	**phv;
	long	init_time;
	int		i;


	phv = malloc(sizeof(t_philo *) * args->philo); // What can be the diff between allocating with the sizeof (t_philo *) and the sizeof (t_philo)
	if (!phv)
			return ((t_philo **)malloc_fail());
	i = 0;
	while (i < args->philo)
	{
		phv[i] = malloc(sizeof(t_philo));
		if (!phv[i])
			return ((t_philo **)malloc_fail());
		init_time = get_time(0);
		phv[i]->n_philos = args->philo;
		phv[i]->init_time = init_time;
		phv[i]->last_eat = init_time;
		phv[i]->id = i + 1;
		phv[i]->t_die = args->t_die;
		phv[i]->t_eat = args->t_eat;
		phv[i]->t_sleep = args->t_sleep;
		phv[i]->ts_eat = args->ts_eat;
		phv[i]->forks = forks;	
		i++;
	}
	return (phv);
	// This function returns an array of pointers to philo struct
}

int	create_philos(t_arg *prop, t_cmp *comp, int m)
{
	int		i;

	i = 0;
	while (i < prop->philo)
	{
		if (i % 2 == m)
		{
			if (pthread_create(&comp->threads[i], NULL, setup_routines, (void *)comp->philos[i]))
				return (1);
			if (usleep(100))
				return (1);
		}
		i++;
	}
	// for (int i = 0; i < prop->philo; i++)
	// 	pthread_join(comp->threads[i], NULL);
	return (0);
}

t_cmp	*launch_philos(t_arg *prop)
{
	t_cmp	*comp;
	t_mutex	*forks;

	comp = malloc(sizeof(t_cmp));
	if (!comp)
		return ((t_cmp *)malloc_fail());
	comp->threads = malloc(sizeof(pthread_t) * prop->philo);
	forks =	create_forks(prop);
	if (!comp->threads || !forks) // create_forks may fail in two cases; either the malloc fail or the pthread_mutex fail
		return ((t_cmp *)malloc_fail());
	comp->philos = get_philos_prop(prop, forks);
	if (!comp->philos)
		return ((t_cmp *)malloc_fail());
	// for (int i = 0; i < prop->philo; i++)
	// 	printf("philo n: %d\n", comp->philos[i]->id);
	if (create_philos(prop, comp, 1) || \
		create_philos(prop, comp, 0))
		return ((t_cmp *)pthr_fail());
	return (comp);
}


/*
	seperating the protection of malloc and pthread in some lines above
*/