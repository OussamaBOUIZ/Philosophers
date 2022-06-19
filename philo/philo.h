/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:56:58 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/19 19:33:57 by obouizga         ###   ########.fr       */
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

typedef struct s_philo
{
	int	id;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	ts_eat;
}				t_philo;

typedef struct	s_rout_a
{
	t_arg	*args;
	int		i;
}				t_rout_a;

typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_time;

void		*set_up_routines(t_mutex *forks, void	*arg);
void		pthr_fail(void);
int			is_integer(char	*s);
t_arg		*check_get_args(int ac, char **av);
int			ft_atoi(const char *str);
void		*malloc_fail(void);
pthread_t	*create_philos(t_arg *args);

#endif