/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_forms_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 02:56:28 by atambo            #+#    #+#             */
/*   Updated: 2024/11/01 02:56:45 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrb(t_vars *a)
{
	r_rotate(&(a->st_b));
	put_index(&(a->st_b));
	a->moves += 1;
	ft_printf("rrb\n");
	if (a->show_state)
		print_status(a);
}

void	pa(t_vars *a)
{
	push(&(a->st_a), &(a->st_b));
	put_index(&(a->st_a));
	put_index(&(a->st_b));
	a->moves += 1;
	ft_printf("pb\n");
	if (a->show_state)
		print_status(a);
}

void	pb(t_vars *a)
{
	push(&(a->st_b), &(a->st_a));
	put_index(&(a->st_a));
	put_index(&(a->st_b));
	a->moves += 1;
	ft_printf("pa\n");
	if (a->show_state)
		print_status(a);
}

void	rrr(t_vars *a)
{
	rra(a);
	rrb(a);
	a->moves -= 1;
	ft_printf("rrr\n");
	if (a->show_state)
		print_status(a);
}

void	rr(t_vars *a)
{
	ra(a);
	rb(a);
	a->moves -= 1;
	ft_printf("rr\n");
	if (a->show_state)
		print_status(a);
}
