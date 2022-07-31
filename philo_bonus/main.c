/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:13:27 by obouizga          #+#    #+#             */
/*   Updated: 2022/07/31 18:36:46 by obouizga         ###   ########.fr       */
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

int main(int ac ,char **av)
{
	t_arg	*args;

	args = check_get_args(ac, av);
	if (!args)
		return (1);
	launch_procs(args);
	return (0);
}
