/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:13:27 by obouizga          #+#    #+#             */
/*   Updated: 2022/08/08 11:50:52 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
void	display_arr(pid_t *pids, int n)
{
	for (int i = 0; i < n; i++)
		printf("[%d]\n", pids[i]);
}

pid_t	*set_pids(int n)
{
	pid_t	*pids = malloc(sizeof(pid_t) * n);
	if (!pids)
		perror("Malloc");
	for (int i = 0; i < n; i++)
		pids[i] = -1;
	return (pids);
}
int	in_parent_proc(pid_t *pids, int n)
{
	for (int i = 0; i < n; i++)
		if (!pids[i])
			return (1);
	return (0);	
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int n = atoi(av[1]);
	int	*pids = set_pids(n);
	display_arr(pids, n);
	// return (1);
	for (int i = 0; i < n; i++)
	{
		if (!in_parent_proc(pids, n))
			pids[i] = fork();
		if (!pids[i])
			printf("Hi from the child proc | pid : [%d] | ppid : [%d]\n", getpid(), getppid());
		
	}
	if (!in_parent_proc(pids, n))
			sleep(1);
	return (0);
}
//A process ID value of 1 indicates that there is no parent process associated with the calling process.