/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:56:38 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/22 12:31:59 by obouizga         ###   ########.fr       */
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

#include <string.h>

int main(int ac, char **av)
{
	t_arg	*args;
	t_cmp	*comp;
	int		i;

	for (size_t o = 0 ; av[o]; o++)
	{
		if (strlen(av[o]) == 0)
			return (0);
	}
	args = check_get_args(ac, av);
	if (!args)
		return (1);
	comp = launch_philos(args);
	if (!comp)
		return (1);
	i = 0;
	while (1)
	{
		i = 0;
		while (comp->philos[i])
		{
			if (get_time(0) - comp->philos[i]->last_eat > comp->philos[i]->t_die)
			{
				printf("%ld %d has   died\n", get_time(comp->philos[i]->init_time),\
				comp->philos[i]->id);
				exit(1);
			}
			i++;
		}
	}	
	return (0);
}
