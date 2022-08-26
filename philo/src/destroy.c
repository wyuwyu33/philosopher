/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 03:36:10 by wyu               #+#    #+#             */
/*   Updated: 2022/08/26 18:41:17 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_destroy(t_monitor *monitor)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < monitor->nbr_of_philo)
	{
		if (!pthread_mutex_unlock(&monitor->forks[i]))
			pthread_mutex_destroy(&monitor->forks[i]);
		i++;
	}
	if (!pthread_mutex_unlock(&monitor->lock_print))
		pthread_mutex_destroy(&monitor->lock_print);
	i = 0;
	philo = monitor->philos;
	while (i < monitor->nbr_of_philo)
	{
		if (!pthread_mutex_unlock(&philo[i].lock_meal))
			pthread_mutex_destroy(&philo[i].lock_meal);
		i++;
	}
}
