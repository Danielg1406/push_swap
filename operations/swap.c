/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:09:31 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/08 13:22:00 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	t_node	*temp;

	if (!a)
		return;
	temp = a->top;
	a->top = a->top->next;
	a->top->next = temp;
	printf("sa\n");
}

void	ft_sb(t_stack *b)
{
	t_node	*temp;

	if (!b)
		return;
	temp = b->top;
	b->top = b->top->next;
	b->top->next = temp;
	printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return;
	ft_sa(a);
	ft_sb(b);
	printf("ss");
	return;
}
