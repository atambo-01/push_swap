/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:30:59 by atambo            #+#    #+#             */
/*   Updated: 2024/10/14 11:40:41 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_index(t_list **head)
{
	int		i;
	t_list	*temp;

	i = 1;
	temp = *head;
	while (temp)
	{
		temp->i = i++;
		temp = temp->next;
	}
}

static t_list	*get_index_2(int i, t_list **head)
{
	t_list	*temp;
	int		len;

	if (!head || !*head)
		return (NULL);
	temp = (*head);
	len = list_size(*head) + i;
	if (len < 0)
		return (NULL);
	while (len-- > 0 && temp->next)
		temp = temp->next;
	return (temp);
}

t_list	*get_index(int i, t_list **head)
{
	t_list	*temp;

	if (*head && i > 0)
	{
		temp = *head;
		while (--i > 0 && temp)
			temp = temp->next;
		return (temp);
	}
	else if (*head && i <= 0)
		return (get_index_2(i, head));
	return (NULL);
}

void	add_top(int value, t_list **head)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->i = 0;
	new_node->next = *head;
	*head = new_node;
}

void	add_tail(int value, t_list **head)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->i = 0;
	new_node->next = NULL;
	if (!*head)
		*head = new_node;
	else
	{
		temp = *head;
		temp = get_index(-1, &temp);
		if (temp)
			temp->next = new_node;
	}
}
