/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 08:07:26 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/29 16:36:27 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	malloc_fail(void)
{
	printf("Malloc failed\n");
	exit(EXIT_FAILURE);
}

void	semaph_fail(void)
{
	printf("SEMAPHORE FAILED\n");
	exit(EXIT_FAILURE);
}

void	fork_fail(void)
{
	printf("FORK FAILED\n");
	exit(EXIT_FAILURE);
}

