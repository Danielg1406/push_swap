/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:40:13 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/11 12:52:23 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_initialize(t_stack **a, t_stack **b, int *parsed_values, int array_len)
{
	int	i;

	i = 0;
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	(*a)->top = NULL;
	(*a)->bottom = NULL;
	(*b)->top = NULL;
	(*b)->bottom = NULL;
	ft_init_stack(&(*a)->top, &(*a)->bottom, parsed_values[0], 0);
	while (++i < array_len)
		ft_insert_end(&(*a)->bottom, parsed_values[i], i);
	return (0);
}

int	*ft_assign_new_position(int *parsed_values, int *sorted_values, int len)
{
	int	*new_positions;
	int	i;
	int	j;

	new_positions = (int *)malloc(len * sizeof(int));
	if (!new_positions)
	{
		free(sorted_values);
		return (0);
	}
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (parsed_values[i] == sorted_values[j])
			{
				new_positions[i] = j + 1;
				break ;
			}
		}
	}
	return (new_positions);
}

//TODO: Create own qsort function
void	ft_normalize_data(int *parsed_values, int len, t_stack *a)
{
	int		*sorted_values;
	int		*new_positions;
	t_node	*cur;
	int		index;

	sorted_values = (int *)malloc(len * sizeof(int));
	if (!sorted_values)
		return ;
	ft_memcpy(sorted_values, parsed_values, len * sizeof(int));
	qsort(sorted_values, len, sizeof(int), ft_compare_value);
	new_positions = ft_assign_new_position(parsed_values, sorted_values, len);
	if (!new_positions)
		return ;
	cur = a->top;
	index = 0;
	while (cur && index < len)
	{
		cur->position = new_positions[index++];
		cur = cur->next;
	}
	free(sorted_values);
	free(new_positions);
}
