/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:14:21 by atambo            #+#    #+#             */
/*   Updated: 2024/10/08 19:04:30 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../sources/libft/libft.h"
# include "../sources/ft_printf/includes/ft_printf.h"
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				i;
	struct s_list	*next;
}t_list;

typedef struct s_vars
{
	t_list	*st_a;
	t_list	*st_b;
	t_list	*ord;
	t_list	*temp;
	char	**in;
	int		moves;
	int		show_state;
	int		time;
}	t_vars;

void	free_all(t_vars *a);

//check_inputs_01
void	ft_error_ps(t_vars *a, int e);
void	ft_has_duplicates(t_vars *a);
t_list	*av_to_list(char **av, t_vars *a);
void	ft_check_one_dig(char **av, t_vars *a);

//check_inputs_02
void	list_verify(t_vars *a);

//ft_atoi_ps
int		ft_atoi_ps(const char *nptr, int *i);

//ft_split_ps
char	**ft_split_ps(char **str, char div);

//higher_sort
void	print_status(t_vars *a);
t_list	*copy_list(t_list **st_a);
void	remove_node(t_list **head, t_list *targ);
t_list	*order_list(t_vars *a);
int		get_st_quantil(t_vars *a, int qnt, int nth);

//lesser_sort
void	sort_2(t_vars *a);
void	sort_3(t_vars *a);
void	sort_4(t_vars *a);
void	sort_5(t_vars *a);
void	sort_b_3(t_vars *a);

//list_utils
void	print_list(t_list *head, int i, int h);
int		list_size(t_list *head);
void	free_list(t_list **head);

// operations_01
void	put_index(t_list **head);
t_list	*get_index(int i, t_list **head);
void	add_top(int value, t_list **head);
void	add_tail(int value, t_list **head);
t_list	*get_tail(t_list **head);

//operations_02
void	rem_top(t_list **head);
void	swap(t_list **st);
void	push(t_list **send, t_list **get);
void	rotate(t_list **head);
void	r_rotate(t_list **head);

//operations_03
t_list	*get_max(t_list **st);
t_list	*get_min(t_list **st);
void	mech_turk(t_vars *a);

//push_swap_utils
void	print_stacks(t_list **st_a, t_list **st_b);
int		is_sorted(t_list *head);

t_list	*find_in_list(t_list **head, int var);

//short_forms_01
void	sa(t_vars *a);
void	sb(t_vars *a);
void	rra(t_vars *a);
void	ra(t_vars *a);
void	rb(t_vars *a);

//short_forms_02
void	rrb(t_vars *a);
void	pa(t_vars *a);
void	pb(t_vars *a);
void	rrr(t_vars *a);
void	rr(t_vars *a);

//sort_6_plus
t_list	*find_target(t_list *st_a, t_list *st_b);
void	push_cheap(t_vars *a, int min_cost, int cost_a, int cost_b);
void	sort_6_plus(t_vars *a);

//sort_b_3
void	sort_b_3(t_vars *a);

#endif
