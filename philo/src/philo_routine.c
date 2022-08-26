/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:38:50 by wyu               #+#    #+#             */
/*   Updated: 2022/08/26 18:53:48 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static
void	ft_taking_forks(t_philo *philo)
{

	pthread_mutex_lock(philo->first);
	pthread_mutex_lock(philo->lock_print);
	ft_print(philo, "has taken a fork");
	pthread_mutex_unlock(philo->lock_print);
	pthread_mutex_lock(philo->second);
	pthread_mutex_lock(philo->lock_print);
	ft_print(philo, "has taken a fork");
	pthread_mutex_unlock(philo->lock_print);
}

static
int	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_meal);
	pthread_mutex_lock(philo->lock_print);
	philo->last_meal_time = ft_current_time();
	ft_print(philo, "is eating");
	pthread_mutex_unlock(philo->lock_print);
	if (philo->limit_active)
		philo->cnt_meals++;
	if (philo->cnt_meals == *philo->limit_nbr_of_meals)
		philo->full = 1;
	pthread_mutex_unlock(&philo->lock_meal);
	ft_usleep(ft_current_time(), philo->time_to_eat);
	pthread_mutex_unlock(philo->second);
	pthread_mutex_unlock(philo->first);
	return (philo->full);
}

static
void	ft_sleeping(t_philo *philo)
{
	long long	start_time;

	start_time = ft_current_time();
	pthread_mutex_lock(philo->lock_print);
	ft_print(philo, "is sleeping");
	pthread_mutex_unlock(philo->lock_print);
	ft_usleep(start_time, philo->time_to_sleep);
}

static
void	ft_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->lock_print);
	ft_print(philo, "is thinking");
	pthread_mutex_unlock(philo->lock_print);
}

void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (*philo->alone)
	{
		pthread_mutex_lock(philo->first);
		pthread_mutex_lock(philo->lock_print);
		ft_print(philo, "has taken a fork");
		pthread_mutex_unlock(philo->lock_print);
		pthread_mutex_unlock(philo->first);
		return (NULL);
	}
	if (philo->id % 2)
		usleep(philo->time_to_eat * 1000);
	while (!*philo->death)
	{
		ft_taking_forks(philo);
		if (ft_eating(philo))
			return (NULL);
		ft_sleeping(philo);
		ft_thinking(philo);
		usleep(500);
	}
	return (NULL);
}