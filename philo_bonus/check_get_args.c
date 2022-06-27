/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_get_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 06:52:21 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/27 17:19:53 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	verif_argnum(int ac)
{
	if (ac < 5)
		return (incomplete_arguments());
	else if (ac > 6)
		return (extra_arguments());
	return (0);
}	

int	check_integer(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
		if (!is_integer(av[i]))
			return (invalid_arguments());
	return (0);
}

int	check_zero_str_num(int ac, char **av)
{
	int	i;

	if (!ft_atoi(av[1]))
		return (zero_philos());
	i = 0;
	while (++i < ac)
		if (!ft_strlen(av[i]))
			return (empty_arg());
	return (0);
}

int	check_short_times(int ac, char **av)
{
	int	i;

	i = 1;
	while (++i < ac)
		if (ft_atoi(av[i]) < 60)
			return (invalid_timing());
	return (0);
}

t_arg	*check_get_args(int ac, char **av)
{
	t_arg	*args;

	if (verif_argnum(ac) || check_integer(ac, av) || \
	check_zero_str_num(ac, av) || check_range(av, ac) || \
	check_short_times(ac, av))
		return (0);
	args = malloc(sizeof(t_arg));
	if (!args)
		return ((t_arg *)malloc_fail());
	args->num_ph = ft_atoi(av[1]);
	args->t_die = ft_atoi(av[2]);
	args->t_eat = ft_atoi(av[3]);
	args->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		args->ts_eat = ft_atoi(av[5]);
		if (!args->ts_eat)
			return (never_eat());
	}
	else
		args->ts_eat = -1;
	return (args);
}
