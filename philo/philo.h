/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:56:58 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/24 11:29:22 by obouizga         ###   ########.fr       */
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

#include <stdio.h>

typedef struct timeval t_tval;  // number of i's right neighbor
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_time;
typedef struct s_arg
{
	int	num_ph;
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
	long	last_eat;
	t_mutex	*forks;
	t_mutex	*lock_write;
}				t_philo;

typedef struct s_cmp
{
	pthread_t	*threads;
	t_philo		**philos;
}				t_cmp;


long		get_time(long curr);
void		*set_up_routines(void	*arg);
void		*pthr_fail(void);
int			is_integer(char	*s);
t_arg		*check_get_args(int ac, char **av);
int			ft_atoi(const char *str);
void		*malloc_fail(void);
t_cmp		*launch_philos(t_arg *args);
size_t		ft_strlen(char *s);
void		lock_print(char *s, long time, int id, t_mutex *lock, int l_u);

#endif
