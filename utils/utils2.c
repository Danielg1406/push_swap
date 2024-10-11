/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:20:23 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/11 12:10:21 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_manage_sign(const char **str_ptr, int *sign)
{
	const char	*str;

	str = *str_ptr;
	*sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*(str + 1) == '+' || *(str + 1) == '-')
			return (0);
		if (*(str + 1) == '0' && *(str + 2) == '\0')
			return (0);
		if (*str == '-')
			*sign = -1;
		str++;
	}
	if (*str == '0' && *(str + 1) != '\0')
		return (0);
	*str_ptr = str;
	return (1);
}

int	ft_atol(const char *str, long *result)
{
	int		sign;
	int		digit;
	long	num;

	sign = 1;
	num = 0;
	if (!ft_manage_sign(&str, &sign))
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		digit = *str - '0';
		if (sign == 1 && num > (INT_MAX - digit) / 10)
			return (0);
		if (sign == -1 && (-(num) < (INT_MIN + digit) / 10))
			return (0);
		num = num * 10 + digit;
		str++;
	}
	*result = num * sign;
	return (1);
}

int	ft_ascending(int a, int b)
{
	if (a < b)
		return (1);
	return (0);
}

int	ft_compare_value(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
