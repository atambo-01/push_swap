/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:55:36 by atambo            #+#    #+#             */
/*   Updated: 2024/11/01 01:57:24 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	parse_digits(const char *nptr, long *res, int sign)
{
	while (ft_isdigit(*nptr))
	{
		*res = *res * 10 + (*nptr - '0');
		if ((*res * sign) > INT_MAX || (*res * sign) < INT_MIN)
			return (0);
		nptr++;
	}
	return (*nptr == '\0');
}

int	ft_atoi_ps(const char *nptr, int *i)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	if (!nptr || !i)
		return (0);
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	if (!parse_digits(nptr, &res, sign))
		return (0);
	*i = (int)(res * sign);
	return (1);
}
