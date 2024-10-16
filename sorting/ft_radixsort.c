/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:58:27 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/12 17:57:13 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	t_node	*cur;
	int		size;

	size = 0;
	cur = stack->top;
	while(cur)
	{
		size++;
		cur = cur->next;
	}
	return (size);
}

int	ft_max_bits(t_stack *stack)
{
	int		max_bits;
	int		max_value;
	t_node	*cur;

	cur = stack->top;
	max_bits = 0;
	max_value = cur->position;
	while (cur)
	{
		if (cur->position > max_value)
			max_value = cur->position;
		cur = cur->next;
	}
	while ((max_value >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_optimize_rotation(t_stack *a, t_stack *b)
{
	while (a->top && b->top)
	{
		if (condition_to_rotate_both(a, b))
			ft_rrr(a, b);
		else if (condition_for_ra(a))
			ft_ra(a, 1);
		else if (condition_for_rb(b))
			ft_rb(b, 1);
		else
			break ;

	}
}

void	ft_radix(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	i = -1;
	max_bits = ft_max_bits(a);
	size = ft_stack_size(a);
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((a->top->position >> i) & 1) == 0)
				ft_pb(b, a);
			else
				ft_ra(a, 1);
		}
		while (b->top != NULL)
			ft_pa(a, b);
	}
}
