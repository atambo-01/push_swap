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
