/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:13:27 by obouizga          #+#    #+#             */
/*   Updated: 2022/08/02 08:34:34 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*
	* num_of_philos
	* time_to_die
	* time_to_eat
	* time_to_sleep
	* [number_of_times_each_phil_must_eat]

*/
int	check_die(t_cmp	*comp, t_arg *args)
{
	int	i;

	i = 0;
	while (i < args->num_ph)
	{
		if (get_time(0) - comp->philos[i]->last_eat >= comp->philos[i]->t_die)
		{
			lock_print_death("has died", get_time(comp->philos[i]->init_time), \
			comp->philos[i]->id, comp->philos[i]->w_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_nums_time_toeat(t_cmp *comp, t_arg *args)
{
	int	i;

	i = 0;
	while (i < args->num_ph)
	{
		if (comp->philos[i]->ts_eat < args->ts_eat)
			return (0);
		i++;
	}
	return (1);
}


void	program_finish(t_cmp *cmp, t_arg *args, int (*f)(t_cmp *, t_arg *))
{
	if (f)
	{
		while (1)
		{
			if ((f)(cmp, args) || check_die(cmp, args))
				exit(EXIT_FAILURE);
			usleep(500);
		}
	}
	else
	{
		while (1)
		{
			if (check_die(cmp, args))
				exit(EXIT_FAILURE);
			usleep(500);
		}
	}
}

int main(int ac ,char **av)
{
	t_arg	*args;
	t_cmp	*comp;

	args = check_get_args(ac, av);
	if (!args)
		return (1);
	comp = launch_procs(args);
	if (comp->pids[0])
	{
		if (args->ts_eat != -1)
			program_finish(comp, args, check_nums_time_toeat);
		else
			program_finish(comp, args, NULL);
		return (0);
	}
}
