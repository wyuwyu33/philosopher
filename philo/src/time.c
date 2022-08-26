/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:25:38 by wyu               #+#    #+#             */
/*   Updated: 2022/08/26 18:53:04 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long long	ft_current_time(void)
{
	struct timeval	time;
	long long		ret_ms;

	gettimeofday(&time, NULL);
	ret_ms = (long long)(time.tv_sec * 1000) + (long long)(time.tv_usec / 1000);
	return (ret_ms);
}
