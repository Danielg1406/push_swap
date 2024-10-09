/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:44:36 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/09 12:52:55 by dgomez-a         ###   ########.fr       */
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

	temp = ft_atoi(str);
	if (temp < INT_MIN || temp > INT_MAX)
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

int	ft_error(int *parsed_values)
{
	ft_putendl_fd("Error", 2);
	if (parsed_values)
		free(parsed_values);
	return (0);
}

int	ft_parse_and_check_input(int argc, char **argv, int *parsed_values)
{
	int	value;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		if (!ft_is_valid_int(argv[i]) || !ft_parse_int(argv[i], &value))
			return (ft_error(parsed_values));
		if (ft_is_duplicate_in_input(parsed_values, j, value))
			return (ft_error(parsed_values));
		parsed_values[j++] = value;
	}
	return (1);
}
