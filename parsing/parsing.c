/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:44:36 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/20 15:57:23 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid_int(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_parse_int(const char *str, int *result)
{
	long	temp;

	if (!ft_atol(str, &temp))
		return (0);
	*result = (int)temp;
	return (1);
}

int	ft_is_duplicate_in_input(int *parsed_values, int index, int value)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (parsed_values[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	ft_error(int *parsed_values, char **argv, int argc, int split)
{
	ft_putendl_fd("Error", 2);
	if (parsed_values)
		free(parsed_values);
	if (split)
		ft_free_split(argv, argc);
	return (0);
}

int	ft_parse_and_check_input(int argc, char **argv, int *parsed_values,
		int split)
{
	int	value;
	int	i;
	int	j;

	i = 0;
	if (split)
	{
		i = -1;
		argc -= 1;
	}
	j = 0;
	while (++i < argc)
	{
		if (!ft_is_valid_int(argv[i]) || !ft_parse_int(argv[i], &value))
			return (ft_error(parsed_values, argv, argc, split));
		if (ft_is_duplicate_in_input(parsed_values, j, value))
			return (ft_error(parsed_values, argv, argc, split));
		parsed_values[j++] = value;
	}
	if (ft_input_is_sorted(parsed_values, argc - 1))
	{
		free(parsed_values);
		return (0);
	}
	return (1);
}
