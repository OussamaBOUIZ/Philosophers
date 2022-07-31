/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_mess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:36:40 by obouizga          #+#    #+#             */
/*   Updated: 2022/07/31 16:22:34 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	incomplete_arguments(void)
{
	printf("INCOMPLETE ARGUMENTS ❌\n");
	exit(EXIT_FAILURE);
}

void	extra_arguments(void)
{
	printf("EXTRA ARGUMENTS ❌\n");
	exit(EXIT_FAILURE);
}

void	invalid_arguments(void)
{
	printf("INVALID ARGUMENTS ❌\n");
	exit(EXIT_FAILURE);
}

void	zero_philos(void)
{
	printf("ZERO PHILOS ❌\n");
	exit(EXIT_FAILURE);
}

void	empty_arg(void)
{
	printf("EMPTY ARGUMENT ❌");
	exit(EXIT_FAILURE);
}
