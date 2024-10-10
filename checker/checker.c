/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:15:43 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/10 11:08:33 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_input_is_sorted(int *parsed_values, int array_len)
{	
	int	i;

	i = 0;
	while (i < array_len - 1)
	{
		if (ft_ascending(parsed_values[i], parsed_values[i + 1]) == 0)
			return (0);
		i++;
	}
	return (1);
}
