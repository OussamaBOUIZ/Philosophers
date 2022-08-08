/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:13:27 by obouizga          #+#    #+#             */
/*   Updated: 2022/08/08 12:09:09 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
pid_t	ft_fork(void)
{
	pid_t	id;

	id = fork();
	if (id == -1)
		fork_fail();
	return (id);
}
void	display_arr(pid_t *pids, int n)
{
	for (int i = 0; i < n; i++)
		printf("[%d]\n", pids[i]);
}

pid_t	*set_pids(int n)
{
	pid_t	*pids = malloc(sizeof(pid_t) * n);
	if (!pids)
		malloc_fail();
	for (int i = 0; i < n; i++)
		pids[i] = -42;
	return (pids);
}

int	in_parent_proc(pid_t *pids, int n)
{
	for (int i = 0; i < n; i++)
		if (!pids[i])
			return (1);
	return (0);	
}