/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:56:38 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/13 08:11:26 by obouizga         ###   ########.fr       */
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

int main(int ac, char **av)
{
	t_arg	*args;


	args = check_get_args(ac, av);
	printf("Number of philos : %i\n", args->philo);	
	printf("Time to die : %i\n", args->t_die);	
	printf("Time to eat : %i\n", args->t_eat);	
	printf("Time to sleep : %i\n", args->t_sleep);
	printf("Number of times each philo must eat : %i\n", args->ts_eat);
	return (0);
}
