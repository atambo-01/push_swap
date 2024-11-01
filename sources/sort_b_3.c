/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 02:28:53 by atambo            #+#    #+#             */
/*   Updated: 2024/11/01 02:29:18 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_st_b(t_vars *a)
{
	t_list	*m;
	t_list	*targ;

	while (list_size(a->st_b) > 0)
	{
		m = get_max(&(a->st_b));
		while (a->st_b != m)
			rb(a);
		targ = find_target(a->st_a, a->st_b);
		while (targ->i != 1)
		{
			if (targ->i >= list_size(a->st_a) / 2)
				rra(a);
			else
				ra(a);
		}
		pb(a);
	}
}

static void	sort_min_in_st_a(t_vars *a)
{
	t_list	*m;

	m = get_min(&(a->st_a));
	while (a->st_a != m)
	{
		if (m->i >= list_size(a->st_a) / 2)
			rra(a);
		else
			ra(a);
	}
}

void	sort_b_3(t_vars *a)
{
	sort_st_b(a);
	sort_min_in_st_a(a);
}
