/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:21:55 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/10 16:26:51 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_delete_node(t_node *node)
{
	if (node->previous)
		node->previous->next = node->next;
	if (node->next)
		node->next->previous = node->previous;
	free(node);
}

void	ft_insert_beggining(t_node **top, int value, int position)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = value;
	new->position = position;
	new->previous = NULL;
	new->next = *top;
	if (*top)
		(*top)->previous = new;
	*top = new;
}

void	ft_insert_end(t_node **bottom, int value, int position)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = value;
	new->position = position;
	new->next = NULL;
	if (*bottom == NULL)
	{
		new->previous = NULL;
		*bottom = new;
	}
	else
	{
		new->previous = *bottom;
		(*bottom)->next = new;
		*bottom = new;
	}
}

void	ft_init_stack(t_node **top, t_node **bottom, int value, int position)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = value;
	new->position = position;
	new->previous = NULL;
	new->next = NULL;
	*top = new;
	*bottom = new;
}

void	ft_print_stack(t_stack *stack)
{
	t_node	*cur;

	if (!stack)
		return ;
	cur = stack->top;
	while (cur)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
}
