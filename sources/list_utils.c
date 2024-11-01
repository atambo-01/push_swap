/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:39:29 by atambo            #+#    #+#             */
/*   Updated: 2024/10/14 09:39:30 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_list *head, int i, int h)
{
	char	s;
	int		d;

	put_index(&head);
	while (head != NULL)
	{
		d = head->data;
		s = '-';
		if (head->data >= 0)
			s = '+';
		if (d < 0)
			d = -d;
		ft_printf("%c%d ", s, d);
		if (i > 0)
			ft_printf("\t[%d]", head->i);
		if (h > 0)
			ft_printf("\n");
		head = head->next;
	}
	ft_printf("\n");
}

int	list_size(t_list *head)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = head;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	free_list(t_list **head)
{
	t_list	*temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*head = NULL;
}
