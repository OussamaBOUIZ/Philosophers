/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:35:36 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/19 18:30:35 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating_routine(t_mutex *forks, time_t time_to_eat, int ph_id)
{
	
}

void	*set_up_routines(t_mutex *forks, void	*arg, int ph_id)
{
	t_arg	*prog;

	prog = (t_arg *)arg;
	eating_routine(forks, prog->t_eat, ph_id);
	sleeping_routine();
	thinking_routine();
	return (NULL);
}

