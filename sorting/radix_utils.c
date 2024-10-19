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
