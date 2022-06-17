/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:14:02 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/17 10:19:46 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_t	*cereate_philos(t_arg *args)
{
	pthread_t	*philos;
	int			i;

	philos = malloc(sizeof(pthread_t) * args->philo);
	if (!philos)
		malloc_fail();
	i = -1;
	while (++i < args->philo)	
		pthread_create(&philos[i], NULL, NULL, NULL);
	return (philos);
}

p