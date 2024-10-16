/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:00:47 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/16 15:45:27 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	condition_to_rotate_both(t_stack *a, t_stack *b)
{
	if (a->top && a->top->next && b->top && b->top->next)
	{
		if ((a->top->position > a->top->next->position) && 
			(b->top->position > b->top->next->position))
			return (1);
	}
	return (0);
}

int	condition_for_ra(t_stack *a)
{
	if (a->top && a->top->next)
	{
		if (a->top->position > a->top->next->position)
			return (1);
	}
	return (0);
}

int	condition_for_rb(t_stack *b)
{
	if (b->top && b->top->next)
	{
		if (b->top->position > b->top->next->position)
			return (1);
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_node	*cur;

	cur = stack->top;
	if (!cur || !cur->next)
		return (1);
	while (cur && cur->next)
	{
		if (cur->position > cur->next->position)
			return (0);
		cur = cur->next;
	}
	return (1);
}
