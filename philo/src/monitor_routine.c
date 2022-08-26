/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 02:21:53 by wyu               #+#    #+#             */
/*   Updated: 2022/08/26 18:51:51 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static
int	ft_every_full(t_monitor *monitor)
{
	int	i_philo;

	i_philo = 0;
	while (i_philo < monitor->nbr_of_philo)
	{
		pthread_mutex_lock(&monitor->philos[i_philo].lock_meal);
		if (!monitor->philos[i_philo].full)
		{
			pthread_mutex_unlock(&monitor->philos[i_philo].lock_meal);
			return (0);
		}
		pthread_mutex_unlock(&monitor->philos[i_philo].lock_meal);
		i_philo++;
	}
	return (1);
}

static
void	ft_death(t_monitor *monitor, int i_philo)
{
	pthread_mutex_lock(&monitor->lock_print);
	ft_print(&monitor->philos[i_philo], "died");
	monitor->death = 1;
	pthread_mutex_unlock(&monitor->lock_print);
}

static
int	death_check(t_monitor *monitor, int i_philo, long long current_time)
{
	t_philo	*philo;

	philo = monitor->philos;

	pthread_mutex_lock(&philo[i_philo].lock_meal);
	if (current_time >= \
			monitor->time_to_die + monitor->philos[i_philo].last_meal_time)
	{
		ft_death(monitor, i_philo);
	}
	pthread_mutex_unlock(&philo[i_philo].lock_meal);
	return (monitor->death);
}

void	*ft_monitor_routine(void *arg)
{
	t_monitor	*monitor;
	long long	current_time;
	int			i_philo;

	monitor = (t_monitor *)arg;
	while (!ft_every_full(monitor))
	{
		i_philo = 0;
		current_time = ft_current_time();
		while (i_philo < monitor->nbr_of_philo)
		{
			if (death_check(monitor, i_philo, current_time))
				return (NULL);
			i_philo++;
		}
		usleep(100);
	}
	return (NULL);
}