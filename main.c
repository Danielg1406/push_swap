/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:42:26 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/21 10:36:07 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_elements(t_resources *res)
{
	if (res->parsed_values)
		free(res->parsed_values);
	if (res->a)
		ft_free_stack(res->a);
	if (res->b)
		ft_free_stack(res->b);
	if (res->split)
		ft_free_split(res->argv, res->split);
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
	t_resources	res;
	int			new_argc;

	res.split = 0;
	if (argc < 2)
		return (1);
	res.argv = ft_handle_args(&argc, argv, &res.split);
	new_argc = argc + res.split;
	res.parsed_values = malloc((new_argc - 1) * sizeof(int));
	if (!res.parsed_values || !ft_parse_and_check_input(new_argc, res.argv,
			res.parsed_values, res.split))
		return (1);
	if (ft_input_is_sorted(res.parsed_values, new_argc))
	{
		ft_free_elements(&res);
		return (1);
	}
	ft_initialize(&res.a, &res.b, res.parsed_values, new_argc - 1);
	ft_normalize_data(res.parsed_values, new_argc - 1, res.a);
	ft_sort(res.a, res.b, new_argc - 1);
	ft_free_elements(&res);
	return (0);
}
