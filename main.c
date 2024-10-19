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
	if (a != NULL)
		ft_free_stack(a);
	if (b != NULL)
		ft_free_stack(b);
}

void	ft_sort(t_stack *a, t_stack *b, int argc)
{
	if (argc == 2)
		ft_sa(a, 1);
	else if (argc > 2 && argc <= 5)
		ft_sort_less_five(a, b, argc);
	else
		ft_radix(a, b);
}

// int	ft_count_split(char **split)
// {
// 	int	count;

// 	count = 0;
// 	while (split[count])
// 		count++;
// 	return (count);
// }

// char	**ft_handle_args(int *argc, char **argv, int *split)
// {
// 	if (*argc == 2 && ft_strchr(argv[1], ' ') != NULL)
// 	{
// 		*split = 1;
// 		argv = ft_split(argv[1], ' ');
// 		*argc = ft_count_split(argv);
// 	}
// 	return (argv);
// }

// TODO: Fix memory leaks, fix Norminette
int	main(int argc, char **argv)
{
	int		*parsed_values;
	t_stack	*a;
	t_stack	*b;

	// int		split;
	// int		arg_count;
	// split = 0;
	if (argc < 3)
		return (1);
	// argv = ft_handle_args(&argc, argv, &split);
	// if (split)
	// 	arg_count = ft_count_split(argv);
	// else
	// 	arg_count = argc - 1;
	parsed_values = malloc((argc - 1) * sizeof(int));
	if (!parsed_values || !ft_parse_and_check_input(argc, argv, parsed_values))
		return (1);
	ft_initialize(&a, &b, parsed_values, argc - 1);
	ft_normalize_data(parsed_values, argc - 1, a);
	ft_sort(a, b, argc - 1);
	ft_free_elements(a, b, parsed_values);
	// if (split)
	// 	ft_free_split(argv, 0);
	return (0);
}
