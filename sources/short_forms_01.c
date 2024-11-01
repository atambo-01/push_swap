/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_forms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:48:44 by atambo            #+#    #+#             */
/*   Updated: 2024/10/18 18:48:46 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_vars *a)
{
	swap(&(a->st_a));
	put_index(&(a->st_a));
	a->moves += 1;
	ft_printf("sa\n");
	if (a->show_state)
		print_status(a);
}

void	sb(t_vars *a)
{
	swap(&(a->st_b));
	put_index(&(a->st_b));
	a->moves += 1;
	ft_printf("sb\n");
	if (a->show_state)
		print_status(a);
}

void	rra(t_vars *a)
{
	r_rotate(&(a->st_a));
	put_index(&(a->st_a));
	a->moves += 1;
	ft_printf("rra\n");
	if (a->show_state)
		print_status(a);
}

void	ra(t_vars *a)
{
	rotate(&(a->st_a));
	put_index(&(a->st_a));
	a->moves += 1;
	ft_printf("ra\n");
	if (a->show_state)
		print_status(a);
}

void	rb(t_vars *a)
{
	rotate(&(a->st_b));
	put_index(&(a->st_b));
	a->moves += 1;
	ft_printf("rb\n");
	if (a->show_state)
		print_status(a);
}
