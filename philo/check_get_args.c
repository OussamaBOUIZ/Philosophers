/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_get_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 06:52:21 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/13 08:13:13 by obouizga         ###   ########.fr       */
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

void	verif_argnum(int ac)
{
	if (ac < 5)
	{
		printf("INCOMPLETE ARGUMENTS ❌\n");
		exit(EXIT_FAILURE);
	}
	else if (ac > 6)
	{
		printf("EXTRA ARGUMENTS ❌\n");
		exit(EXIT_FAILURE);
	}	
}	

void	check_integer(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_integer(av[i]))
		{
			printf("ARG NOT INTEGER ❌\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

t_arg	*check_get_args(int ac, char **av)
{
	t_arg	*args;
	
	verif_argnum(ac);
	check_integer(ac, av);
	args = malloc(sizeof(t_arg));
	if (!args)
		malloc_fail();
	args->philo = ft_atoi(av[1]);
	args->t_die = ft_atoi(av[2]);
	args->t_eat = ft_atoi(av[3]);
	args->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->ts_eat = ft_atoi(av[5]);
	else
		args->ts_eat = -1;
	return (args);
}