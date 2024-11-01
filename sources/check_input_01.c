/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:37:50 by atambo            #+#    #+#             */
/*   Updated: 2024/11/01 14:37:53 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error_ps(t_vars *a, int e)
{
	ft_printf("Error\n");
	free_all(a);
	exit(e);
}

void	ft_has_duplicates(t_vars *a)
{
	t_list	*temp_1;
	t_list	*temp_2;

	temp_1 = a->st_a;
	while (temp_1)
	{
		temp_2 = temp_1->next;
		while (temp_2)
		{
			if (temp_1->data == temp_2->data)
			{
				ft_error_ps(a, 4);
			}
			temp_2 = temp_2->next;
		}
		temp_1 = temp_1->next;
	}
}

t_list	*av_to_list(char **av, t_vars *a)
{
	int		i;
	t_list	*head;
	int		data;

	i = 0;
	head = NULL;
	while (av[i])
	{
		if (ft_atoi_ps(av[i], &data))
			add_tail(data, &head);
		else
		{
			free(head);
			ft_error_ps(a, 4);
		}
		i++;
	}
	return (head);
}

void	ft_check_one_dig(char **av, t_vars *a)
{
	int	i;
	int	j;
	int	has_digit;

	i = 0;
	while (av[i])
	{
		j = 0;
		has_digit = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
			{
				has_digit = 1;
				break ;
			}
			j++;
		}
		if (!has_digit)
			ft_error_ps(a, 3);
		i++;
	}
}
