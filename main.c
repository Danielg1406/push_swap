/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:42:26 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/17 17:57:49 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_elements(t_stack *a, t_stack *b, int *parsed_values)
{
	if (parsed_values)
		free(parsed_values);
	if (a)
		ft_free_stack(a);
	if (b)
		ft_free_stack(b);
}

void	ft_sort(t_stack *a, t_stack *b, int argc)
{
	if (argc == 2)
		ft_sa(a, 1);
	else
		ft_radix(a, b);
}

int	ft_count_split(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

char	**ft_handle_args(int *argc, char **argv, int *split)
{
	if (*argc == 2 && ft_strchr(argv[1], ' ') != NULL)
	{
		*split = 1;
		argv = ft_split(argv[1], ' ');
		*argc = ft_count_split(argv);
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	int		*parsed_values;
	int		split;
	int		arg_count;
	t_stack	*a;
	t_stack	*b;

	split = 0;
	if (argc < 2)
		return (1);
	argv = ft_handle_args(&argc, argv, &split);
	if (split)
		arg_count = ft_count_split(argv);
	else
		arg_count = argc - 1;
	parsed_values = malloc(arg_count * sizeof(int));
	if (!parsed_values || !ft_parse_and_check_input(arg_count + 1, argv, parsed_values) 
		|| ft_input_is_sorted(parsed_values, arg_count))
		return (1);
	ft_initialize(&a, &b, parsed_values, arg_count);
	ft_normalize_data(parsed_values, arg_count, a);
	ft_sort(a, b, arg_count);
	ft_free_elements(a, b, parsed_values);
	if (split)
		ft_free_split(argv, 0);
	return (0);
}
