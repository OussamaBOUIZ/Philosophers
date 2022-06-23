/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:59:35 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/23 18:06:29 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	lock_print(char *s, long time, int id, t_mutex *lock, int l_u)
{
	pthread_mutex_lock(lock);
	printf("%ld %i %s\n", time, id, s);
	if (l_u == 1)
		pthread_mutex_unlock(lock);
}
