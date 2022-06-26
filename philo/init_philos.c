/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:14:02 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/26 15:46:58 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_mutex	*create_forks(t_arg	*args)
{
	t_mutex	*forks;
	int		i;

	forks = malloc(sizeof(t_mutex) * (args->num_ph));
	if (!forks)
		return ((t_mutex *)malloc_fail());
	i = -1;
	while (++i < (args->num_ph))
		if (pthread_mutex_init(&forks[i], NULL))
			return ((t_mutex *)pthr_fail());
	return (forks);
}

void	handle_opt_arg(t_arg *args, t_philo *ph)
{
	if (args->ts_eat != -1)
		ph->ts_eat = 0;
	else
		ph->ts_eat = -1;
}

t_philo	**get_philos_prop(t_arg	*args, t_mutex *forks, t_mutex *lock_write)
{
	t_philo	**phv;
	int		i;

	phv = malloc(sizeof(t_philo) * args->num_ph);
	if (!phv)
		return ((t_philo **)malloc_fail());
	i = -1;
	while (++i < args->num_ph)
	{
		phv[i] = malloc(sizeof(t_philo));
		if (!phv[i])
			return ((t_philo **)malloc_fail());
		phv[i]->n_philos = args->num_ph;
		phv[i]->id = i + 1;
		phv[i]->t_die = args->t_die;
		phv[i]->t_eat = args->t_eat;
		phv[i]->t_sleep = args->t_sleep;
		phv[i]->ts_eat = args->ts_eat;
		phv[i]->forks = forks;
		phv[i]->lock_write = lock_write;
		phv[i]->init_time = get_time(0);
		phv[i]->last_eat = get_time(0);
		handle_opt_arg(args, phv[i]);
	}
	return (phv);
}

int	create_philos(t_arg *arg, t_cmp *comp, int m)
{
	int		i;

	i = 0;
	while (i < arg->num_ph)
	{
		if (i % 2 == m)
		{
			if (pthread_create(&comp->threads[i], NULL, set_up_routines, \
			(void *)comp->philos[i]))
				return (1);
		}
		usleep(50);
		i++;
	}
	return (0);
}

t_cmp	*launch_philos(t_arg *args)
{
	t_cmp	*comp;
	t_mutex	*forks;
	t_mutex	*lock_write;

	lock_write = malloc(sizeof(t_mutex));
	comp = malloc(sizeof(t_cmp));
	if (!comp)
		return ((t_cmp *)malloc_fail());
	comp->threads = malloc(sizeof(pthread_t) * args->num_ph);
	forks = create_forks(args);
	if (!comp->threads || !forks)
		return ((t_cmp *)malloc_fail());
	if (pthread_mutex_init(lock_write, NULL))
		return ((t_cmp *)pthr_fail());
	comp->philos = get_philos_prop(args, forks, lock_write);
	if (!comp->philos)
		return ((t_cmp *)malloc_fail());
	if (create_philos(args, comp, 1) || \
		create_philos(args, comp, 0))
		return ((t_cmp *)pthr_fail());
	return (comp);
}
