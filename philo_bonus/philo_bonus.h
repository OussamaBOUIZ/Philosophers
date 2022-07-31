/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:56:58 by obouizga          #+#    #+#             */
/*   Updated: 2022/07/31 16:36:35 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

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

void		incomplete_arguments(void);
void		extra_arguments(void);
void		invalid_arguments(void);
void		zero_philos(void);
void		empty_arg(void);
void		invalid_timing(void);
void		never_eat(void);
long		get_time(long curr);
size_t		ft_strlen(char *s);
void		setup_routines(t_philo *philo);
void		*pthr_fail(void);
int			is_integer(char	*s);
t_arg		*check_get_args(int ac, char **av);
int			ft_atoi(const char *str);
void		malloc_fail(void);
void		semaph_fail(void);
void		fork_fail(void);
void		launch_procs(t_arg *args);
size_t		ft_strlen(char *s);
void		lock_print(char *s, long time, int id, t_mutex *lock);
void		lock_print_death(char *s, long time, int id, t_mutex *lock);
int			check_range(char **nums, int n);
void		ft_usleep(long time_to_eat);
#endif
