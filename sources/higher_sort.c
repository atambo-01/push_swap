/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   higher_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:40:07 by atambo            #+#    #+#             */
/*   Updated: 2024/11/01 02:18:06 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_status(t_vars *a)
{
	if (a->time >= 0)
	{
		ft_printf("move_count = %d\n", a->moves);
		ft_printf("t_a size = %d\n", list_size(a->st_a));
		print_stacks(&(a->st_a), &(a->st_b));
		if (a->time > 0)
		{
			usleep(a->time);
			system("clear");
		}
	}
	return ;
}

t_list	*copy_list(t_list **st_a)
{
	t_list	*temp;
	t_list	*res;

	temp = *st_a;
	res = NULL;
	while (temp)
	{
		add_tail(temp->data, &res);
		temp = temp->next;
	}
	return (res);
}

void	remove_node(t_list **head, t_list *targ)
{
	t_list	*temp;
	t_list	*prev;

	temp = *head;
	prev = NULL;
	while (temp != NULL && temp != targ)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	if (prev == NULL)
		*head = temp->next;
	else
		prev->next = temp->next;
	free(temp);
}

t_list	*order_list(t_vars *a)
{
	t_list	*ordered;
	t_list	*min;
	t_list	*temp;

	put_index(&(a->st_a));
	ordered = NULL;
	temp = copy_list(&(a->st_a));
	while (temp)
	{
		min = get_min(&temp);
		add_tail(min->data, &ordered);
		remove_node(&temp, min);
	}
	free_list(&temp);
	return (ordered);
}

int	get_st_quantil(t_vars *a, int qnt, int nth)
{
	t_list	*ret;
	int		quantil;
	int		pos;

	if (qnt == 0 || nth >= qnt)
		return (0);
	if (a->temp)
		free_list(&(a->temp));
	a->temp = order_list(a);
	pos = ((list_size(a->st_a) * nth) / qnt) + 1;
	ret = get_index(pos, &(a->temp));
	quantil = ret->data;
	return (quantil);
}
