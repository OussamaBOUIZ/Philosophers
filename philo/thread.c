/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:04:02 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/14 12:11:46 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*my_turn(void *arg)
{
	int	i;

	(void)arg;
	i = -1;
	while (1)
	{
		sleep(1);
		printf("My turn\n");
	}
	return (NULL);
}

void	*your_turn(void *arg)
{
	int	i;

	(void)arg;
	i = -1;
	while (++i < 5)
	{
		sleep(1);
		printf("Your turn\n");
	}
	return (NULL);
}

int main(void)
{	
	pthread_t thread;
	pthread_create(&thread, NULL, my_turn, NULL);
	your_turn(NULL);
	return (0);	
}