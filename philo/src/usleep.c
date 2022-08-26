/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:18:15 by wyu               #+#    #+#             */
/*   Updated: 2022/08/26 18:53:10 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_usleep(long long start_time, long long time_to)
{
	while (ft_current_time() < start_time + time_to)
		usleep(100);
}
