/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:59:35 by obouizga          #+#    #+#             */
/*   Updated: 2022/08/02 07:58:04 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	lock_print(char *s, long time, int id, sem_t *sem)
{
	if (sem_wait(sem))
		semaph_fail();
	printf("%ld ms %i %s\n", time, id, s);
	if (sem_post(sem))
		semaph_fail();
	sem_unlink("write_lock");
}


void	lock_print_death(char *s, long time, int id, sem_t *sem)
{
	if (sem_wait(sem))
		semaph_fail();
	printf("%ld ms %i %s\n", time, id, s);
}
