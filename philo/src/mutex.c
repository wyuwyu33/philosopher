/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 03:09:37 by wyu               #+#    #+#             */
/*   Updated: 2022/08/26 18:51:29 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_get_forks(t_monitor *monitor)
{
	int	i_fork;

	monitor->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
													monitor->nbr_of_philo);
	if (!monitor->forks)
		return (1);
	i_fork = 0;
	while (i_fork < monitor->nbr_of_philo)
	{
		if (pthread_mutex_init(&monitor->forks[i_fork], NULL))
			return (1);
		i_fork++;
	}
	return (0);
}

int	ft_init_mutex(t_monitor *monitor)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < monitor->nbr_of_philo)
	{
		if (pthread_mutex_init(&monitor->forks[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&monitor->lock_print, NULL))
		return (1);
	i = 0;
	philo = monitor->philos;
	while (i < monitor->nbr_of_philo)
	{
		if (pthread_mutex_init(&philo[i].lock_meal, NULL))
			return (1);
		i++;
	}
	return (0);
}
