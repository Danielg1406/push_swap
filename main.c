/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:42:26 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/12 17:53:02 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*parsed_values;
	t_stack	*a;
	t_stack	*b;

	if (argc < 3)
		return (1);
	a = NULL;
	b = NULL;
	parsed_values = malloc((argc - 1) * sizeof(int));
	if (!parsed_values || !ft_parse_and_check_input(argc, argv, parsed_values) 
		|| ft_input_is_sorted(parsed_values, argc - 1))
		return (1);
	ft_initialize(&a, &b, parsed_values, argc - 1);
	ft_normalize_data(parsed_values, argc - 1, a);
	ft_radix(a, b);
	free(parsed_values);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
