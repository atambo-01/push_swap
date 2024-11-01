/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 04:03:41 by atambo            #+#    #+#             */
/*   Updated: 2024/11/01 04:04:03 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	best_move(t_vars *a, t_list *best, t_list *targ)
{
	if (best->i != 1 || targ->i != 1)
	{
		if (best->i != 1 && best->i > list_size(a->st_b) / 2)
			rrb(a);
		else if (best->i != 1 && best->i <= list_size(a->st_b) / 2)
			rb(a);
		else if (targ->i != 1 && targ->i > list_size(a->st_a) / 2)
			rra(a);
		else if (targ->i != 1 && targ->i <= list_size(a->st_a) / 2)
			ra(a);
	}
	else
		pb(a);
}

t_list	*find_target(t_list *st_a, t_list *st_b)
{
	t_list	*t_1;
	t_list	*t_2;

	t_1 = st_a;
	t_2 = NULL;
	while (t_1)
	{
		if (t_1->data > st_b->data && (!t_2 || t_1->data < t_2->data))
			t_2 = t_1;
		t_1 = t_1->next;
	}
	return (t_2);
}

int	calculate_cost(t_vars *a, t_list *temp, int *cost_a, int *cost_b)
{
	t_list	*targ;

	targ = find_target(a->st_a, temp);
	*cost_a = targ->i - 1 - (list_size(a->st_a)
			* (targ->i > list_size(a->st_a) / 2));
	*cost_b = temp->i - 1 - (list_size(a->st_b)
			* (temp->i > list_size(a->st_b) / 2));
	return (ft_abs(*cost_a) + ft_abs(*cost_b) + 1);
}

void	push_cheap(t_vars *a, int min_cost, int cost_a, int cost_b)
{
	t_list	*temp;
	t_list	*best;
	t_list	*targ;
	int		t_c;

	min_cost = INT_MAX;
	temp = a->st_b;
	best = NULL;
	while (temp)
	{
		t_c = calculate_cost(a, temp, &cost_a, &cost_b);
		if (t_c < min_cost)
		{
			min_cost = t_c;
			best = temp;
		}
		temp = temp->next;
	}
	if (best)
	{
		targ = find_target(a->st_a, best);
		best_move(a, best, targ);
	}
}

void	sort_6_plus(t_vars *a)
{
	int		quantil;
	int		div;
	t_list	*last;

	last = get_index(-1, &(a->st_a));
	div = 2;
	quantil = get_st_quantil(a, div, 1);
	while (list_size(a->st_a) > 3)
	{
		if ((a->st_a)->data <= quantil)
		{
			pa(a);
			last = get_index(-1, &(a->st_a));
		}
		else
			ra(a);
		if (a->st_a == last)
		{
			quantil = get_st_quantil(a, div, 1);
			last = get_index(-1, &(a->st_a));
		}
	}
	sort_3(a);
	mech_turk(a);
}
