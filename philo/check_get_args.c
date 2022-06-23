/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_get_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 06:52:21 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/23 12:30:29 by obouizga         ###   ########.fr       */
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

int	verif_argnum(int ac)
{
	if (ac < 5)
	{
		printf("INCOMPLETE ARGUMENTS ❌\n");
		return (1);
	}
	else if (ac > 6)
	{
		printf("EXTRA ARGUMENTS ❌\n");
		return (1);
	}
	return (0);
}	

int	check_integer(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_integer(av[i]))
		{
			printf("ARG NOT INTEGER ❌\n");
			return (1);
		}
		i++;
	}
	return (0);
}

size_t	check_empty_str(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac )
		if (!ft_strlen(av[i]))
		{
			printf("EMPTY ARG ❌\n");
			return (1);
		}
	return (0);
}
/*
	To-do:
	- protecting malloc by return value rather than using exit
*/
t_arg	*check_get_args(int ac, char **av)
{
	t_arg	*args;
	
	if (verif_argnum(ac) ||\
	 check_integer(ac, av) ||\
	 check_empty_str(ac, av))
		return (0);
	args = malloc(sizeof(t_arg));
	if (!args)
		return ((t_arg *)malloc_fail());
	args->num_ph = ft_atoi(av[1]);
	args->t_die = ft_atoi(av[2]);
	args->t_eat = ft_atoi(av[3]);
	args->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->ts_eat = ft_atoi(av[5]);
	else
		args->ts_eat = -1;
	return (args);
}