/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:52:15 by atambo            #+#    #+#             */
/*   Updated: 2024/10/08 18:53:21 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_vars	*init_all(t_vars *a)
{
	a = malloc(sizeof(t_vars));
	if (!a)
		ft_error_ps(a, 1);
	a->st_a = NULL;
	a->st_b = NULL;
	a->ord = NULL;
	a->temp = NULL;
	a->in = NULL;
	a->moves = 0;
	a->show_state = 1;
	a->time = -1;
	return (a);
}

static void	checks(t_vars *a, char **av)
{
	ft_check_one_dig(&av[1], a);
	a->in = ft_split_ps(&av[1], ' ');
	ft_check_one_dig(a->in, a);
	list_verify(a);
	a->st_a = av_to_list(a->in, a);
	ft_has_duplicates(a);
	a->ord = order_list(a);
	return ;
}

static void	free_matrix(char **mat)
{
	int	i;

	i = 0;
	if (!mat)
		return ;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

void	free_all(t_vars *a)
{
	if (a->st_a != NULL)
		free_list(&(a->st_a));
	if (a->st_b != NULL)
		free_list(&(a->st_b));
	if (a->ord != NULL)
		free_list(&(a->ord));
	if (a->temp != NULL)
		free_list(&(a->temp));
	if (a-> in != NULL)
		free_matrix(a->in);
	free(a);
}

int	main(int ac, char **av)
{
	t_vars	*a;

	if (ac > 1)
	{
		a = NULL;
		a = init_all(a);
		checks(a, av);
		if (!is_sorted(a->st_a))
		{
			if (list_size(a->st_a) >= 6)
				sort_6_plus(a);
			else if (list_size(a->st_a) == 5)
				sort_5(a);
			else if (list_size(a->st_a) == 4)
				sort_4(a);
			else if (list_size(a->st_a) == 3)
				sort_3(a);
			else if (list_size(a->st_a) == 2)
				sort_2(a);
		}
		free_all(a);
	}
	return (0);
}
