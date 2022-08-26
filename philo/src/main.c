/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:38:32 by wyu               #+#    #+#             */
/*   Updated: 2022/08/26 18:37:20 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static
void	ft_resource_return(t_monitor *monitor)
{
	ft_destroy(monitor);
	ft_dealloc(monitor);
}

static
int	ft_resource_allocate(t_monitor *monitor)
{
	if (ft_get_forks(monitor) || \
	ft_get_philos(monitor) || \
	ft_init_philos(monitor) || \
	ft_init_mutex(monitor))
		return (1);
	return (0);
}

static
void	ft_detach_philos(t_monitor *monitor)
{
	int	i_philo;

	i_philo = 0;
	while (i_philo < monitor->nbr_of_philo)
	{
		pthread_detach(monitor->philos[i_philo].thread);
		i_philo++;
	}
}

static
void	ft_wait_thread(t_monitor *monitor)
{
	int	i_philo;

	i_philo = 0;
	while (i_philo < monitor->nbr_of_philo)
	{
		pthread_join(monitor->philos[i_philo].thread, NULL);
		i_philo++;
	}
	pthread_join(monitor->thread, NULL);
}

int	main(int argc, char **argv)
{
	t_monitor	monitor;

	if (ft_arg_check(argc, argv))
		return (ft_error("arg error"));
	ft_init_monitor(&monitor, argc, argv);
	if (ft_resource_allocate(&monitor))
	{
		ft_resource_return(&monitor);
		return (1);
	}
	if (ft_start_philos(&monitor))
	{
		ft_detach_philos(&monitor);
		return (1);
	}
	ft_wait_thread(&monitor);
	ft_resource_return(&monitor);
	return (0);
}
