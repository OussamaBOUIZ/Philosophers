/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_mess_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:43:02 by obouizga          #+#    #+#             */
/*   Updated: 2022/07/31 16:22:58 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	invalid_timing(void)
{
	printf("INVALID TIMING ❌\n");
	exit(EXIT_FAILURE);
}

void	never_eat(void)
{
	printf("PHILOS WOULD NEVER EAT ❌\n");
	exit(EXIT_FAILURE);
}
