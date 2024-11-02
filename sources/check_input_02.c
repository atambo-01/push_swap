/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:34:39 by atambo            #+#    #+#             */
/*   Updated: 2024/11/01 14:35:15 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define I_MAX "2147483647"
#define I_MIN "2147483648"

static int	check_limits(const char *start, int sign)
{
	if (ft_abs(sign) > 10)
		return (0);
	if (ft_abs(sign) == 10)
	{
		if ((sign > 0 && ft_strcmp(start, I_MAX) > 0)
			|| (sign < 0 && ft_strcmp(start, I_MIN) > 0))
			return (0);
	}
	return (1);
}

static int	is_within_int_range(const char *str)
{
	const char	*start;
	int			sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	start = str;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		sign = sign + (ft_abs(sign) / sign);
		str++;
	}
	return (check_limits(start, sign));
}

void	list_verify(t_vars *a)
{
	char	**temp;
	int		i;
	int		j;

	temp = a->in;
	i = -1;
	while (temp[++i])
	{
		j = 0;
		if (temp[i][j] == '-' || temp[i][j] == '+')
			j++;
		while (temp[i][j])
		{
			if (!ft_isdigit(temp[i][j]))
				ft_error_ps(a, 2);
			j++;
		}
		if (!is_within_int_range(temp[i]))
			ft_error_ps(a, 2);
	}
}
