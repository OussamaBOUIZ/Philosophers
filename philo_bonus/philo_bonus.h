/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:56:58 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/29 16:19:35 by obouizga         ###   ########.fr       */
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
# include <stdio.h>
# include <semaphore.h>

typedef struct timeval	t_tval;
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_time;

typedef struct s_arg
{
	int	num_ph;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	ts_eat;
}			t_arg;

typedef struct s_philo
{
	unsigned int	n_philos;
	long			init_time;
	int				id;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				ts_eat;
	long			last_eat;
	sem_t			*semaph;
	t_mutex			*lock_write;
}				t_philo;

typedef struct s_cmp
{
	pid_t	*pids;
	t_philo	**philos;
	sem_t	*semaph;
}				t_cmp;

int			incomplete_arguments(void);
int			extra_arguments(void);
int			invalid_arguments(void);
int			zero_philos(void);
int			empty_arg(void);
int			invalid_timing(void);
t_arg		*never_eat(void);
long		get_time(long curr);
void		*set_up_routines(void	*arg);
void		*pthr_fail(void);
int			is_integer(char	*s);
t_arg		*check_get_args(int ac, char **av);
int			ft_atoi(const char *str);
void		malloc_fail(void);
void		semaph_fail(void);
t_cmp		*launch_philos(t_arg *args);
size_t		ft_strlen(char *s);
void		lock_print(char *s, long time, int id, t_mutex *lock);
void		lock_print_death(char *s, long time, int id, t_mutex *lock);
int			check_range(char **nums, int n);
void		ft_usleep(long time_to_eat);
#endif
