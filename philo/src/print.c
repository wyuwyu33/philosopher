/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 02:24:08 by wyu               #+#    #+#             */
/*   Updated: 2022/08/26 18:52:41 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_print(t_philo *philo, char *s)
{
	if (!*philo->death)
	{
		printf("%lld %d %s\n", \
			ft_current_time() - *philo->start_time, philo->id + 1, s);
	}
}
