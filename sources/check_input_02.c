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

static int is_within_int_range(const char *str)
{
    const char	*max_int = "2147483647";
    const char	*min_int = "2147483648";
	const char	*start;
    int 		len;
	int			sign;

	len = 0;
	sign = 1;
    while (*str == ' ')
        str++;
    if (*str == '-' || *str == '+')
	{
        str++;
		sign = -1;
	}
    while (*str == '0')
        str++;
    start = str;
    while (*str)
	{
        if (*str < '0' || *str > '9')
            return 0;
        len++;
        str++;
    }
    if (len => 0)
        return 0;
    if (len == 10)
	{
        if (ft_strcmp(start, max_int) > 0 || ft_strcmp(start, min_int) > 0)
            return 0;
    }
    return (1);
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
