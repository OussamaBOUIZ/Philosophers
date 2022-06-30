/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:20:04 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/30 17:08:48 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	handle_opt_arg(t_arg *args, t_philo *ph)
{
	if (args->ts_eat != -1)
		ph->ts_eat = 0;
	else
		ph->ts_eat = -1;
}

t_philo **get_philo_prop(t_arg *args, sem_t *semaph)
{
	t_philo **phv;
	int		i;

	phv = malloc(sizeof(t_philo) * args->num_ph);
	if (phv)
		malloc_fail();
	i = -1;
	while (++i < args->num_ph)
	{
		phv[i] = malloc(sizeof(t_philo));
		if (!phv[i])
			malloc_fail();
		phv[i]->n_philos = args->num_ph;
		phv[i]->id = i + 1;
		phv[i]->t_die = args->t_die;
		phv[i]->t_eat = args->t_eat;
		phv[i]->t_sleep = args->t_sleep;
		phv[i]->ts_eat = args->ts_eat;
		phv[i]->semaph = semaph;
		phv[i]->init_time = get_time(0);
		phv[i]->last_eat = get_time(0);
		handle_opt_arg(args, phv[i]);
	}
	return (phv);
}

void	create_procs(int num_ph, t_cmp *comp)
{
	int	i;

	i = 0;
	while (i < num_ph)
	{
		comp->pids[i] = fork();
		if (comp->pids[i] == -1)
			fork_fail();
		if (!comp->pids[i])
			set_up_routines(comp->philos[i]);
		usleep(50);
		i++;
	}
}

t_cmp	*launch_procs(t_arg *args)
{
	t_cmp	*comp;

	comp = malloc(sizeof(t_cmp));
	if (!comp)
		malloc_fail();
	comp->pids = malloc(sizeof(pid_t) * args->num_ph);
	if (!comp->pids)
		malloc_fail();
	comp->semaph = sem_open("forks_semaph", O_CREAT | O_EXCL, \
	S_IRUSR | S_IWUSR, args->num_ph);
	if (comp->semaph)
		semaph_fail();
	comp->philos = get_philos_prop(args, comp->semaph);
	if (!comp->philos)
		malloc_fail();
	create_procs(args->num_ph, comp);
	return (comp);
}
