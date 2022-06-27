/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_mess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:36:40 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/27 15:46:33 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	incomplete_arguments(void)
{
	printf("INCOMPLETE ARGUMENTS ❌\n");
	return (1);
}

int	extra_arguments(void)
{
	printf("EXTRA ARGUMENTS ❌\n");
	return (1);
}

int	invalid_arguments(void)
{
	printf("INVALID ARGUMENTS ❌\n");
	return (1);
}

int	zero_philos(void)
{
	printf("ZERO PHILOS ❌\n");
	return (1);
}

int	empty_arg(void)
{
	printf("EMPTY ARGUMENT ❌");
	return (1);
}
