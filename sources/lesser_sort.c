/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lesser_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:05:29 by atambo            #+#    #+#             */
/*   Updated: 2024/10/14 16:05:31 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_vars *a)
{
	int	an;
	int	bn;

	if (list_size(a->st_a) > 1)
	{
		an = a->st_a->data;
		bn = a->st_a->next->data;
		if (an > bn)
			sa(a);
	}
}

void	sort_3(t_vars *a)
{
	t_list	*max;

	if (a->st_a)
	{
		max = get_max(&(a->st_a));
		if (a->st_a == max)
			ra(a);
		else if (a->st_a->next == max)
			rra(a);
		sort_2(a);
	}
}

void	sort_4(t_vars *a)
{
	t_list	*min;

	while (list_size(a->st_a) > 3)
	{
		min = get_min(&(a->st_a));
		while (a->st_a != min)
		{
			if (min->i < list_size(a->st_a) / 2)
				ra(a);
			else
				rra(a);
		}
		pa(a);
	}
	if (!is_sorted(a->st_a))
		sort_3(a);
	pb(a);
}

void	sort_5(t_vars *a)
{
	t_list	*min;

	min = get_min(&(a->st_a));
	while (list_size(a->st_a) > 3)
	{
		if (min->i < list_size(a->st_a) - 1)
			ra(a);
		if (min->i >= list_size(a->st_a) - 1)
			rra(a);
		if (a->st_a == min)
			pa(a);
		min = get_min(&(a->st_a));
	}
	if (!is_sorted(a->st_a))
	{	
		sort_3(a);
		if (get_max(&(a->st_b)) != a->st_b)
			sb(a);
	}
	pb(a);
	pb(a);
}
