/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:27:15 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/10 15:50:51 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	t_node	*new_top;

	if (!b || !b->top || !a)
		return ;
	new_top = b->top;
	b->top = new_top->next;
	if (b->top)
		b->top->previous = NULL;
	ft_insert_beggining(&a->top, new_top->data, new_top->position);
	ft_delete_node(new_top);
	printf("pa\n");
}

void	ft_pb(t_stack *b, t_stack *a)
{
	t_node	*new_top;

	if (!a || !a->top || !b)
		return ;
	new_top = a->top;
	a->top = new_top->next;
	if (a->top)
		a->top->previous = NULL;
	ft_insert_beggining(&b->top, new_top->data, new_top->position);
	ft_delete_node(new_top);
	printf("pb\n");
}
