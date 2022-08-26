/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:30:15 by wyu               #+#    #+#             */
/*   Updated: 2022/08/26 18:52:30 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_get_philos(t_monitor *monitor)
{
	monitor->philos = (t_philo *)malloc(sizeof(t_philo) * \
										monitor->nbr_of_philo);
	if (!monitor->philos)
		return (1);
	return (0);
}

static
void	ft_init_philo_forks(t_philo *philo, t_monitor *monitor)
{
	if (philo->id % 2 == 0)
	{
		philo->first = monitor->forks + philo->id;
		philo->second = monitor->forks + \
							((philo->id + 1) % monitor->nbr_of_philo);
	}
	else
	{
		philo->second = monitor->forks + philo->id;
		philo->first = monitor->forks + \
							((philo->id + 1) % monitor->nbr_of_philo);
	}
}

int	ft_init_philos(t_monitor *monitor)
{
	t_philo	*philo;
	int		i_philo;

	i_philo = 0;
	philo = monitor->philos;
	memset((void *)philo, 0, sizeof(t_philo) * monitor->nbr_of_philo);
	while (i_philo < monitor->nbr_of_philo)
	{
		philo[i_philo].id = i_philo;
		philo[i_philo].time_to_eat = monitor->time_to_eat;
		philo[i_philo].time_to_sleep = monitor->time_to_sleep;
		philo[i_philo].alone = (const int *)&monitor->alone;
		philo[i_philo].limit_active = (const int *)&monitor->limit_active;
		philo[i_philo].limit_nbr_of_meals = \
									(const int *)&monitor->limit_nbr_of_meals;
		philo[i_philo].death = (const int *)&monitor->death;
		philo[i_philo].start_time = (const long long *)&monitor->start_time;
		ft_init_philo_forks(&philo[i_philo], monitor);
		philo[i_philo].lock_print = &monitor->lock_print;
		i_philo++;
	}
	return (0);
}

int	ft_start_philos(t_monitor *monitor)
{
	t_philo	*philo;
	int		i_philo;

	i_philo = 0;
	philo = monitor->philos;
	monitor->start_time = ft_current_time();
	while (i_philo < monitor->nbr_of_philo)
	{
		philo[i_philo].last_meal_time = monitor->start_time;
		i_philo++;
	}
	if (pthread_create(&monitor->thread, NULL, \
			ft_monitor_routine, (void *)monitor))
		return (1);
	i_philo = 0;
	while (i_philo < monitor->nbr_of_philo)
	{
		if (pthread_create(&philo[i_philo].thread, NULL, \
				ft_philo_routine, (void *)&philo[i_philo]))
			return (1);
		i_philo++;
	}
	return (0);
}
