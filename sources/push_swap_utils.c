/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:57:47 by atambo            #+#    #+#             */
/*   Updated: 2024/10/18 13:57:48 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_list **st_a, t_list **st_b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = *st_a;
	temp_b = *st_b;
	put_index(st_a);
	put_index(st_b);
	while (temp_a || temp_b)
	{
		if (temp_a)
		{
			ft_printf("[%d]\t[%d]", temp_a->data, temp_a->i);
			temp_a = temp_a->next;
		}
		else
			ft_printf("\t");
		if (temp_b)
		{
			ft_printf("\t\t[%d]\t[%d]", temp_b->data, temp_b->i);
			temp_b = temp_b->next;
		}
		ft_printf("\n");
	}
}

int	is_sorted(t_list *head)
{
	int	i;

	if (head)
	{
		i = head->data;
		while (head)
		{
			if (head->data < i)
				return (0);
			i = head->data;
			head = head->next;
		}
	}
	return (1);
}
