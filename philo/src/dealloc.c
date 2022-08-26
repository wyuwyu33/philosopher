/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:10:46 by wyu               #+#    #+#             */
/*   Updated: 2022/08/26 18:41:15 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_dealloc(t_monitor *monitor)
{
	free(monitor->forks);
	monitor->forks = NULL;
	free(monitor->philos);
	monitor->philos = NULL;
}
