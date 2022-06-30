/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:06:01 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/30 17:17:25 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	setup_routines(t_philo *philo)
{
	while (1)
	{
		eating_routine(philo);
		sleeping_routine(philo);
		thinking_routine(philo);
	}
}