/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:27:15 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/08 17:32:29 by dgomez-a         ###   ########.fr       */
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
	b->top->previous = NULL;
	ft_insert_beggining(&a->top, new_top->data);
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
	a->top->previous = NULL;
	ft_insert_beggining(&b->top, new_top->data);
	ft_delete_node(new_top);
	printf("pb\n");
}
