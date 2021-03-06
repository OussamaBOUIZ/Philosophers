/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:13:27 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/30 16:59:52 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int ac ,char **av)
{
	t_arg	*args;
	t_cmp	*component;

	args = check_get_args(ac, av);
	if (!args)
		return (1);
	component = launch_procs(args);
	if (!component)
		return (1);
	return (0);
}
