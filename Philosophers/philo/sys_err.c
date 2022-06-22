/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 08:07:26 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/20 15:34:36 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*malloc_fail(void)
{
	printf("Malloc failed\n");
	return (0);
}


void	*pthr_fail(void)
{
	printf("Pthread failed\n");
	return (0);
}