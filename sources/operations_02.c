/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 02:35:46 by atambo            #+#    #+#             */
/*   Updated: 2024/11/01 02:36:42 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rem_top(t_list **head)
{
	t_list	*old_head;

	if (!head || !*head)
		return ;
	old_head = *head;
	*head = (*head)->next;
	free(old_head);
}

void	swap(t_list **st)
{
	t_list	*t1;
	t_list	*t2;

	if (!st || !*st || !(*st)->next)
		return ;
	t1 = *st;
	t2 = (*st)->next;
	t1->next = t2->next;
	t2->next = t1;
	(*st) = t2;
}

void	push(t_list **send, t_list **get)
{
	if (send && *send)
	{
		add_top((*send)->data, get);
		rem_top(send);
	}
}

void	rotate(t_list **head)
{
	t_list	*tail;
	t_list	*i_2;

	if (list_size(*head) > 1)
	{
		i_2 = (*head)->next;
		tail = get_index(0, head);
		tail->next = (*head);
		(*head)->next = NULL;
		(*head) = i_2;
	}
}

void	r_rotate(t_list **head)
{
	t_list	*tail;
	t_list	*tail_prev;

	if (list_size(*head) > 1)
	{
		tail_prev = get_index(-2, head);
		tail = get_index(-1, head);
		tail_prev->next = NULL;
		tail->next = (*head);
		(*head) = tail;
	}
}
