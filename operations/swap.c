/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:09:31 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/08 17:31:52 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, int flag)
{
	t_node	*temp;

	if (!a || !a->top || !a->top->next)
		return ;
	temp = a->top;
	a->top = a->top->next;
	temp->next = a->top->next;
	if (a->top->next)
		a->top->next->previous = temp;
	a->top->previous = NULL;
	a->top->next = temp;
	temp->previous = a->top;
	if (flag)
		printf("sa\n");
}

void	ft_sb(t_stack *b, int flag)
{
	t_node	*temp;

	if (!b || !b->top || !b->top->next)
		return ;
	temp = b->top;
	b->top = b->top->next;
	temp->next = b->top->next;
	if (b->top->next)
		b->top->next->previous = temp;
	b->top->previous = NULL;
	b->top->next = temp;
	temp->previous = b->top;
	if(flag)
		printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ft_sa(a, 0);
	ft_sb(b, 0);
	printf("ss");
}
