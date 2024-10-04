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

int	ft_sa(t_stack *a)
{
	t_node	*temp;

	if (!a)
		return (0);
	temp = a;
	a = a->next;
	a->next = temp;
	return (1);
}

int	ft_sb(t_stack *b)
{
	t_node	*temp;

	if (!b)
		return (0);
	temp = b;
	b = b->next;
	b->next = temp;
}

int	ft_ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	ft_sa(a);
	ft_sb(b);
	return (1);
}
