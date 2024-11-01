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

static int	is_within_int_range(const char *str)
{
	const char	*max_int = "2147483647";
	const char	*min_int = "2147483648";
	int			len;

	len = ft_strlen(str);
	if (len > 11 || (len == 11 && str[0] != '-')
		|| (len == 10 && str[0] != '-' && ft_strcmp(str, max_int) > 0))
		return (0);
	if (str[0] == '-' && len >= 10 && ft_strcmp(str + 1, min_int) > 0)
		return (0);
	if (str[0] != '-' && len == 10 && ft_strcmp(str, max_int) > 0)
		return (0);
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
