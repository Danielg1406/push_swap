/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:31:58 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/20 15:33:19 by dgomez-a         ###   ########.fr       */
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

void	ft_sort_five(t_stack *a, t_stack *b)
{
	printf("sort 5\n");
	if (a->top && b->top)
		printf("first a: %d first b: %d\n", a->top->position, b->top->position);
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
