/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 02:37:12 by atambo            #+#    #+#             */
/*   Updated: 2024/11/01 02:37:25 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*get_max(t_list **st)
{
	t_list	*max;
	t_list	*temp;

	if (*st)
	{
		temp = *st;
		max = *st;
		while (temp)
		{
			if (max->data < temp->data)
				max = temp;
			temp = temp->next;
		}
		return (max);
	}
	return (NULL);
}

t_list	*get_min(t_list **st)
{
	t_list	*min;
	t_list	*temp;

	if (*st)
	{
		temp = *st;
		min = *st;
		while (temp)
		{
			if (min->data > temp->data)
				min = temp;
			temp = temp->next;
		}
		return (min);
	}
	return (NULL);
}

void	mech_turk(t_vars *a)
{
	while (list_size(a->st_b) > 3)
		push_cheap(a, 0, 0, 0);
	sort_b_3(a);
}
