/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:40:13 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/10 13:53:51 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_initialize(t_stack **a, t_stack **b, int *parsed_values, int array_len)
{
	int	i;

	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	(*a)->top = NULL;
	(*a)->bottom = NULL;
	(*b)->top = NULL;
	(*b)->bottom = NULL;
	ft_init_stack(&(*a)->top, &(*a)->bottom, parsed_values[0]);
	i = 1;
	while (i < array_len)
	{
		ft_insert_end(&(*a)->bottom, parsed_values[i]);
		i++;
	}
	return (0);
}
