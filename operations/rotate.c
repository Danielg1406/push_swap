/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:43:10 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/20 17:08:11 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a, int flag)
{
	t_node	*new_top;

	if (!a->top || !a->top->next)
		return ;
	new_top = a->top;
	a->top = new_top->next;
	a->top->previous = NULL;
	ft_insert_end(&a->bottom, new_top->data, new_top->position);
	ft_delete_node(new_top);
	if (flag)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack *b, int flag)
{
	t_node	*new_top;

	if (!b->top || !b->top->next)
		return ;
	new_top = b->top;
	b->top = new_top->next;
	b->top->previous = NULL;
	ft_insert_end(&b->bottom, new_top->data, new_top->position);
	ft_delete_node(new_top);
	if (flag)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ft_ra(a, 0);
	ft_rb(b, 0);
	write(1, "rr\n", 3);
}
