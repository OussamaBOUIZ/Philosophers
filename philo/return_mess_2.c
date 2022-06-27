/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_mess_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:43:02 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/27 15:58:06 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	invalid_timing(void)
{
	printf("INVALID TIMING ❌\n");
	return (1);
}

t_arg	*never_eat(void)
{
	printf("PHILOS WOULD NEVER EAT ❌\n");
	return (0);
}
