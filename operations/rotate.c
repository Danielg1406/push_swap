/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:43:10 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/10 15:57:20 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a)
{
	t_node	*new_top;

	if (!a->top || !a->top->next)
		return ;
	new_top = a->top;
	a->top = new_top->next;
	a->top->previous = NULL;
	ft_insert_end(&a->bottom, new_top->data, new_top->position);
	ft_delete_node(new_top);
	printf("ra\n");
}

void	ft_rb(t_stack *b)
{
	t_node	*new_top;

	if (!b->top || !b->top->next)
		return ;
	new_top = b->top;
	b->top = new_top->next;
	b->top->previous = NULL;
	ft_insert_end(&b->bottom, new_top->data, new_top->position);
	ft_delete_node(new_top);
	printf("rb\n");
}

void	ft_rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ft_ra(a);
	ft_rb(b);
	printf("rr\n");
}
