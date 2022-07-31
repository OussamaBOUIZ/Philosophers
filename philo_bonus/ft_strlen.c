/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:59:35 by obouizga          #+#    #+#             */
/*   Updated: 2022/07/31 16:24:53 by obouizga         ###   ########.fr       */
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

// void	lock_print(char *s, long time, int id, t_mutex *lock)
// {
// 	pthread_mutex_lock(lock);
// 	printf("%ld ms %i %s\n", time, id, s);
// 	pthread_mutex_unlock(lock);
// }

// void	lock_print_death(char *s, long time, int id, t_mutex *lock)
// {
// 	pthread_mutex_lock(lock);
// 	printf("%ld ms %i %s\n", time, id, s);
// }
