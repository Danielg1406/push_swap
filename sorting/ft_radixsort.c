/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:58:27 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/16 16:58:50 by dgomez-a         ###   ########.fr       */
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

int	ft_define_bit_to_push(t_stack *a, int size, int i)
{
	t_node	*cur;
	int	count_zeros;
	int	count_ones;
	int	j;

	j = 0;
	count_zeros = 0;
	count_ones = 0;
	cur = a->top;
	while (j < size)
	{
		if (((cur->position >> i) & 1) == 0)
			count_zeros++;
		else
			count_ones++;
		cur = cur->next;
		j++;
	}
	if (count_zeros <= count_ones)
		return (0);
	else
		return (1);
}

void	ft_radix(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;
	int	bit_to_push;

	i = 0;
	max_bits = ft_max_bits(a);
	while (i < max_bits)
	{
		size = ft_stack_size(a);
		bit_to_push = ft_define_bit_to_push(a, size, i);
		j = 0;
		while (j < size)
		{
			if (((a->top->position >> i) & 1) == bit_to_push)
				ft_pb(b, a);
			else
				ft_ra(a, 1);
			j++;
		}
		while (b->top)
			ft_pa(a,b);
		i++;
	}
}
