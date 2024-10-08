/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:45:28 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/08 17:33:59 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a)
{
	t_node	*new_bottom;

	if (!a->bottom || !a->bottom->previous)
		return ;
	new_bottom = a->bottom;
	a->bottom = new_bottom->previous;
	a->bottom->next = NULL;
	ft_insert_beggining(&a->top, new_bottom->data);
	ft_delete_node(new_bottom);
	printf("rra\n");
}

void	ft_rrb(t_stack *b)
{
	t_node	*new_bottom;

	if (!b->bottom || !b->bottom->previous)
		return ;
	new_bottom = b->bottom;
	b->bottom = new_bottom->previous;
	b->bottom->next = NULL;
	ft_insert_beggining(&b->top, new_bottom->data);
	ft_delete_node(new_bottom);
	printf("rrb\n");
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ft_rra(a);
	ft_rrb(b);
	printf("rrr\n");
}
