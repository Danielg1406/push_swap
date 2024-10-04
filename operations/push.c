/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:27:15 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/04 19:42:16 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa(t_stack *a, t_stack *b)
{
	ft_lstadd_front(&a->top, &b->top);
	ft_lstdelone(&a->top);
	a->top = a->top->next;
	return (1);
}

int	ft_pb(t_stack *b, t_stack *a)
{
	ft_lstadd_front(&b->top, &a->top);
	ft_lstdelone(&b->top);
	b->top = b->top->next;
	return (1);
}
