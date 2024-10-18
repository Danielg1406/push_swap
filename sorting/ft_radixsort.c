/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:58:27 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/16 18:17:11 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	t_node	*cur;
	int		size;

	size = 0;
	cur = stack->top;
	while (cur)
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

void	ft_radix_stack_b(t_stack *a, t_stack *b, int max_bits, int bit)
{
	int	size;
	int	i;

	size = ft_stack_size(b);
	i = 0;
	while (i < size && bit <= max_bits && !is_sorted(a))
	{
		if (((b->top->position >> bit) & 1) == 0)
			ft_rb(b, 1);
		else
			ft_pa(a, b);
		i++;
	}
	if (is_sorted(a))
	{
		while (b->top)
			ft_pa(a, b);
	}
}

void	ft_radix(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	i = 0;
	max_bits = ft_max_bits(a);
	while (i < max_bits)
	{
		size = ft_stack_size(a);
		j = 0;
		while (!is_sorted(a) && (j < size))
		{
			if (((a->top->position >> i) & 1) == 0)
				ft_pb(b, a);
			else
				ft_ra(a, 1);
			j++;
		}
		ft_radix_stack_b(a, b, max_bits, i + 1);
		i++;
	}
	while (b->top)
		ft_pa(a,b);
}
