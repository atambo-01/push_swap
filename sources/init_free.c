/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:03:08 by atambo            #+#    #+#             */
/*   Updated: 2024/11/02 20:03:10 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_vars	*init_all(t_vars *a)
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

void	free_matrix(char **mat)
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
