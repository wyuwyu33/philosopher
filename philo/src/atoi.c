/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:25:27 by wyu               #+#    #+#             */
/*   Updated: 2022/08/26 18:41:12 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || \
	c == '\n' || c == '\v' || \
	c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	nbr;
	long long	sign;
	size_t		i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	nbr = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (sign * nbr > FT_INT_MAX)
			return (FT_INT_MAX);
		if (sign * nbr < FT_INT_MIN)
			return (FT_INT_MIN);
		i++;
	}
	return ((int)(sign * nbr));
}
