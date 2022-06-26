/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:56:38 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/26 17:12:31 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_die(t_cmp	*comp, t_arg *args)
{
	int	i;

	i = 0;
	while (i < args->num_ph)
	{
		if (get_time(0) - comp->philos[i]->last_eat >= comp->philos[i]->t_die)
		{
			lock_print_death("has died", get_time(comp->philos[i]->init_time), \
			comp->philos[i]->id, comp->philos[i]->lock_write);
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

int	program_finish(t_cmp *cmp, t_arg *args, int (*f)(t_cmp *, t_arg *))
{
	if (f)
	{
		while (1)
		{
			if ((f)(cmp, args) || check_die(cmp, args))
				return (1);
			usleep(500);
		}
	}
	else
	{
		while (1)
		{
			if (check_die(cmp, args))
				return (1);
			usleep(500);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_arg	*args;
	t_cmp	*comp;

	args = check_get_args(ac, av);
	if (!args)
		return (1);
	comp = launch_philos(args);
	if (!comp)
		return (1);
	if (args->ts_eat != -1)
		return (program_finish(comp, args, check_nums_time_toeat));
	else
		return (program_finish(comp, args, NULL));
	return (0);
}
