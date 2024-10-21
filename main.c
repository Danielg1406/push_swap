/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:42:26 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/20 15:46:55 by dgomez-a         ###   ########.fr       */
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
		if (!argv)
		{
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
		*argc = ft_count_split(argv);
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	int		*parsed_values;
	int		split;
	int		new_argc;
	t_stack	*a;
	t_stack	*b;

	split = 0;
	if (argc < 2)
		return (1);
	argv = ft_handle_args(&argc, argv, &split);
	new_argc = argc + split;
	parsed_values = malloc((new_argc - 1) * sizeof(int));
	if (!parsed_values || !ft_parse_and_check_input(new_argc, argv,
			parsed_values, split))
		return (1);
	ft_initialize(&a, &b, parsed_values, new_argc - 1);
	ft_normalize_data(parsed_values, new_argc - 1, a);
	ft_sort(a, b, new_argc - 1);
	ft_free_elements(a, b, parsed_values);
	if (split)
		ft_free_split(argv, argc);
	return (0);
}
