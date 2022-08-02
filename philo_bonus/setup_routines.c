/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:06:01 by obouizga          #+#    #+#             */
/*   Updated: 2022/08/02 07:44:51 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating_routine(t_philo *ph)
{
	if (sem_wait(ph->semaph) ||	sem_wait(ph->semaph))
		semaph_fail();
	lock_print("has taken a fok", get_time(ph->init_time), ph->id, \
	ph->w_lock);
	lock_print("has taken a fork", get_time(ph->init_time), ph->id, \
	ph->w_lock);
	lock_print("is eating", get_time(ph->init_time), ph->id, \
	ph->w_lock);
	if (ph->ts_eat != -1)
		ph->ts_eat++;
	ph->last_eat = get_time(0);
	ft_usleep(ph->t_eat);
	if (sem_post(ph->semaph) || sem_post(ph->semaph))
		semaph_fail();
}

void	sleeping_routine(t_philo *ph)
{
	lock_print("is sleeping", get_time(ph->init_time), ph->id, \
	ph->w_lock);
	ft_usleep(ph->t_sleep);
}

void	thinking_routine(t_philo *ph)
{
	lock_print("is thinking", get_time(ph->init_time), ph->id, \
	ph->w_lock);
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