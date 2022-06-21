/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:14:02 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/21 18:12:30 by obouizga         ###   ########.fr       */
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

t_philo	*get_philo_prop(t_arg	*args, int id, t_mutex *forks)
{
	t_philo	*philo;
	long	init_time;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return ((t_philo *)malloc_fail());
	init_time = get_time(0);
	philo->n_philos = args->philo;
	philo->init_time = init_time;
	philo->last_eat = init_time;
	philo->id = id;
	philo->t_die = args->t_die;
	philo->t_eat = args->t_eat;
	philo->t_sleep = args->t_sleep;
	philo->ts_eat = args->ts_eat;
	philo->forks = forks;
	return (philo);
}

t_philo	**create_philos(t_arg *prop, t_cmp *comp, t_mutex *forks, int m)
{
	int		i;
	t_philo	**philo;
	
	philo = malloc(sizeof(t_philo) * prop->philo);
	if (!philo)
		return ();
	i = 0;
	while (i < prop->philo && i % 2 == m)
	{
		philo[i] = get_philo_prop(prop, i, forks);
		if (pthread_create(&comp->threads[i], NULL, set_up_routines, (void *)philo[i]))
			return (1);
		if (usleep(100))
			return (1);
		i++;
	}
	return (philo);
}

// t_cmp	*launch_philos(t_arg *prop)
// {
// 	t_cmp	*comp;
// 	t_mutex	*forks;
// 	int			i;

// 	comp = malloc(sizeof(t_cmp));
// 	if (!comp)
// 		return ((t_cmp *)malloc_fail());
// 	comp->threads = malloc(sizeof(pthread_t) * prop->philo);
// 	forks =	create_forks(prop);
// 	if (!comp->threads || !forks)
// 		return ((t_cmp *)malloc_fail());
// 	if (create_philos(prop, comp, forks, 1) || \
// 		create_philos(prop, comp, forks, 0))
// 		return ((t_cmp *)pthr_fail());
// 	return (comp);
// }



t_cmp	*launch_philos(t_arg *prop)
{
	t_cmp	*comp;
	t_mutex	*forks;
	int			i;

	comp = malloc(sizeof(t_cmp));
	if (!comp)
		return ((t_cmp *)malloc_fail());
	comp->threads = malloc(sizeof(pthread_t) * prop->philo);
	forks =	create_forks(prop);
	comp->philos =
	if (!comp->threads || !forks)
		return ((t_cmp *)malloc_fail());
	if (create_philos(prop, comp, forks, 1) || \
		create_philos(prop, comp, forks, 0))
		return ((t_cmp *)pthr_fail());
	return (comp);
}