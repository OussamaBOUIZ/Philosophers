/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:56:58 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/21 12:18:40 by obouizga         ###   ########.fr       */
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

typedef struct timeval t_tval;  // number of i's right neighbor
typedef pthread_mutex_t	t_mutex;
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
	int		n_philos;
	long	init_time;
	int		id;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		ts_eat;
	t_mutex	*forks;
}				t_philo;

typedef struct	s_rout_a
{
	t_philo	philo;
	int		id;
}				t_rout_a;

typedef struct timeval	t_time;

void		*set_up_routines(void	*arg);
void		*pthr_fail(void);
int			is_integer(char	*s);
t_arg		*check_get_args(int ac, char **av);
int			ft_atoi(const char *str);
void		*malloc_fail(void);
long		get_time(long curr);
pthread_t	*launch_philos(t_arg *args);

#endif