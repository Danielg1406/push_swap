/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:09:31 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/04 19:42:43 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	t_node	*temp;

	if (!a)
		return;
	temp = a;
	a = a->next;
	a->next = temp;
	ft_putstr("sa\n");
}

void	ft_sb(t_stack *b)
{
	t_node	*temp;

	if (!b)
		return;
	temp = b;
	b = b->next;
	b->next = temp;
	ft_putstr("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return;
	ft_sa(a);
	ft_sb(b);
	return;
}
