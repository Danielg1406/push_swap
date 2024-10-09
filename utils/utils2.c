/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:20:23 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/09 14:36:27 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(const char *str, long *result)
{
	int	sign;
	int	digit;
	long	num;

	sign = 1;
	num = 0;
	if(*str == '-' || *str == '+')
	{
		if(*(str + 1) == '+' || *(str + 1) == '-')
			return (0);
		if(*(str + 1) == '0' && *(str + 2) == '\0')
			return (0);
		if(*str == '-')
			sign = -1;
		str++;
	}
	if(*str == '0' && *(str + 1) != '\0')
		return (0);
	while(*str)
	{
		if(!ft_isdigit(*str))
			return (0);
		digit = *str - '0';
		if(sign == 1 && num > (INT_MAX - digit) / 10)
			return (0);
		if(sign == -1 && -num < (INT_MIN + digit) / 10)
			return (0);
		num = num * 10 + digit;
		str++;
	}
	*result = num * sign;
	return (1);
}
