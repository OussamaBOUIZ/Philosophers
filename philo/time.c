/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:07:02 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/26 15:37:04 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(long curr)
{
	t_tval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - curr);
}

void	ft_usleep(long time)
{
	long	time_to_wait;

	time_to_wait = get_time(0) + time;
	while (get_time(0) < time_to_wait)
		usleep(250);
}
