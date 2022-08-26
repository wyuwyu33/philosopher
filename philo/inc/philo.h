/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:38:27 by wyu               #+#    #+#             */
/*   Updated: 2022/08/26 18:40:36 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

typedef struct s_philo
{
	int				id;
	int				time_to_eat;
	int				time_to_sleep;
	int				cnt_meals;
	int				full;
	const int		*alone;
	const int		*limit_active;
	const int		*limit_nbr_of_meals;
	const int		*death;
	long long		last_meal_time;
	const long long	*start_time;
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;
	pthread_mutex_t	*lock_print;
	pthread_mutex_t	lock_meal;
	pthread_t		thread;

}	t_philo;

typedef struct s_monitor
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				limit_active;
	int				limit_nbr_of_meals;
	int				alone;
	int				death;
	t_philo			*philos;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock_print;
	pthread_t		thread;
}	t_monitor;

// error.c
int			ft_error(char *s);

// argument.c
int			ft_arg_check(int argc, char **argv);

// atoi.c
int			ft_atoi(const char *str);

// monitor.c
void		ft_init_monitor(t_monitor *monitor, int argc, char **argv);
void		ft_start_monitor(t_monitor *monitor);
void		ft_monitor_mode(t_monitor *monitor);

// mutex.c
int			ft_get_forks(t_monitor *monitor);
int			ft_init_mutex(t_monitor *monitor);

// philosopher.c
int			ft_get_philos(t_monitor *monitor);
int			ft_init_philos(t_monitor *monitor);
int			ft_start_philos(t_monitor *monitor);

// destroy.c
void		ft_destroy(t_monitor *monitor);

// dealloc.c
void		ft_dealloc(t_monitor *monitor);

// time.c
long long	ft_current_time(void);

// philo_routine.c
void		*ft_philo_routine(void *arg);

// print.c
void		ft_print(t_philo *philo, char *s);

// usleep.c
void		ft_usleep(long long start_time, long long time_to);

// monitor_routine.c
void		*ft_monitor_routine(void *arg);
#endif