/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:06:01 by obouizga          #+#    #+#             */
/*   Updated: 2022/07/31 16:27:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating_routine(t_philo *ph)
{
	if (sem_wait(ph->semaph) ||	sem_wait(ph->semaph))
		semaph_fail();
	printf("%ld ms %i has taken a fork\n", get_time(ph->init_time), ph->id);
	printf("%ld ms %i has taken a fork\n", get_time(ph->init_time), ph->id);
	printf("%ld ms %i is eating\n", get_time(ph->init_time), ph->id);
	if (ph->ts_eat != -1)
		ph->ts_eat++;
	ph->last_eat = get_time(0);
	ft_usleep(ph->t_eat);
	if (sem_post(ph->semaph) || sem_post(ph->semaph))
		semaph_fail();
}

void	sleeping_routine(t_philo *ph)
{
	printf("%ld ms %i is sleeping\n", get_time(ph->init_time), ph->id);
	ft_usleep(ph->t_sleep);
}

void	thinking_routine(t_philo *ph)
{
	printf("%ld ms %i is thinking\n", get_time(ph->init_time), ph->id);
}

void	setup_routines(t_philo *philo)
{
	while (1)
	{
		eating_routine(philo);
		sleeping_routine(philo);
		thinking_routine(philo);
	}
}