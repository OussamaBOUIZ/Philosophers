/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:56:38 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/24 16:30:34 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	The program takes as arguments the following:
		number_of_philosophers
		time_to_die 
		time_to_eat
		time_to_sleep
		[number_of_times_each_philosopher_must_eat] (optional)
	
	The program outputs the following:
		◦ time_in_ms X has taken a fork
		◦ time_in_ms X is eating
		◦ time_in_ms X is sleeping
		◦ time_in_ms X is thinking
		◦ time_in_ms X died	
*/

// I SHOULD HANDLE THE OPTIONAL ARGUMENT RIGHT BELOW
int 	check_die(t_cmp	*comp, t_arg *args)
{
	int	i;

	i = 0;
	usleep(500);
	while (i < args->num_ph)
	{
		if (get_time(0) - comp->philos[i]->last_eat >= comp->philos[i]->t_die )
		{
			lock_print("has died", get_time(comp->philos[i]->init_time),\
			comp->philos[i]->id, comp->philos[i]->lock_write, 0);
			return (1);
		}
		i++;
	}
	return (0);
}

//IF ALL PHILOS HAVE EATEN THE NUMBER OF TIME THEY SHOULD THIS FUNCTION RETURNS 1; 
int	check_nums_time_toeat(t_cmp *comp, t_arg *args)
{
	int	i;

	i = 0;
	while (i < args->num_ph)
	{
		if (comp->philos[i]->ts_eat < args->ts_eat)
		{
			lock_print("has died", get_time(comp->philos[i]->init_time),\
			comp->philos[i]->id, comp->philos[i]->lock_write, 0);
			return (0);
		}
		i++;
	}
	return (1);
}

int	program_finish(t_cmp *cmp, t_arg *args, int(*times_to_eat_check)(t_cmp *, t_arg *))
{
	if (times_to_eat_check)
	{
		while (1)
		{
			if (check_die(cmp, args) || (times_to_eat_check)(cmp, args))
				return (1);
		}
	}
	else
	{
		while (1)
			if (check_die(cmp, args))
				return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	t_arg	*args;
	t_cmp	*comp;
	int		m;
	
	m = -1;
	args = check_get_args(ac, av);
	if (!args)
		return (1);
	comp = launch_philos(args);
	if (!comp)
		return (1);
	if (args->ts_eat != -1)
		program_finish(comp, args, check_nums_time_toeat);
	else
		program_finish(comp, args, NULL);
	return (0);
}
