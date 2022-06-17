/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:56:58 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/17 10:36:54 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct timeval t_tval;

typedef struct s_arg
{
	int	philo;
	int t_die;
	int	t_eat;
	int	t_sleep;
	int	ts_eat;
}			t_arg;


int			is_integer(char	*s);
t_arg		*check_get_args(int ac, char **av);
int			ft_atoi(const char *str);
void		malloc_fail(void);
pthread_t	*cereate_philos(t_arg *args);


#endif