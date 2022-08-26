/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:48:46 by wyu               #+#    #+#             */
/*   Updated: 2022/08/26 18:51:24 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_init_monitor(t_monitor *monitor, int argc, char **argv)
{
	memset((void *)monitor, 0, sizeof(t_monitor));
	monitor->nbr_of_philo = ft_atoi(argv[1]);
	monitor->time_to_die = ft_atoi(argv[2]);
	monitor->time_to_eat = ft_atoi(argv[3]);
	monitor->time_to_sleep = ft_atoi(argv[4]);
	if (monitor->nbr_of_philo == 1)
		monitor->alone = 1;
	if (argc == 6)
	{
		monitor->limit_active = 1;
		monitor->limit_nbr_of_meals = ft_atoi(argv[5]);
	}
}
