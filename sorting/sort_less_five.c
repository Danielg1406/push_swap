/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:31:58 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/20 16:59:15 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *a)
{
	while (!is_sorted(a))
	{
		if (a->top->position == 3 && a->top->next->position == 1)
			ft_ra(a, 1);
		else if (a->top->position == 2 && a->top->next->position == 3)
			ft_rra(a, 1);
		else
			ft_sa(a, 1);
	}
}

void	ft_sort_four(t_stack *a, t_stack *b)
{
	while (!is_sorted(a))
	{
		if (a->bottom->position == 4)
			ft_rra(a, 1);
		if (a->top->position == 4)
		{
			ft_pb(b, a);
			ft_sort_three(a);
			ft_pa(a, b);
			ft_ra(a, 1);
		}
		else
			ft_ra(a, 1);
	}
}

int	find_position(t_stack *a, int position)
{
	t_node	*current;
	int		index;

	current = a->top;
	index = 0;
	while (current)
	{
		if (current->position == position)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	int	pos;

	pos = find_position(a, 5);
	if (pos <= 2)
		while (a->top->position != 5)
			ft_ra(a, 1);
	else
		while (a->top->position != 5)
			ft_rra(a, 1);
	ft_pb(b, a);
	ft_sort_four(a, b);
	ft_pa(a, b);
	ft_pa(a, b);
	ft_ra(a, 1);
}

void	ft_sort_less_five(t_stack *a, t_stack *b, int argc)
{
	if (argc == 3)
		ft_sort_three(a);
	else if (argc == 4)
		ft_sort_four(a, b);
	else
		ft_sort_five(a, b);
}
