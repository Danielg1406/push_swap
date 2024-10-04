/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:49:16 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/04 19:07:48 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_define_swap(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		ft_sa();
	else if (ft_strcmp(str, "sb") == 0)
		ft_sb();
	else if (ft_strcmp(str, "ss") == 0)
	{
		ft_sa();
		ft_sb();
	}
}

void	ft_define_push(char *str)
{
	if (ft_strcmp(str, "pa") == 0)
		ft_pa();
	else if (ft_strcmp(str, "pb") == 0)
		ft_pb();
}

void	ft_define_rotate(char *str)
{
	if (ft_strcmp(str, "ra") == 0)
		ft_ra();
	else if (ft_strcmp(str, "rb") == 0)
		ft_rb();
	else if (ft_strcmp(str, "rr") == 0)
	{
		ft_ra();
		ft_rb();
	}
}

void	ft_define_reverse_rotate(char *str)
{
	if (ft_strcmp(str, "rra") == 0)
		ft_rra();
	else if (ft_strcmp(str, "rrb") == 0)
		ft_rrb();
	else if (ft_strcmp(str, "rrr") == 0)
	{
		ft_rra();
		ft_rrb();
	}
}

void	ft_define_operation(char *str)
{
	if (*str == 's')
		ft_define_swap(str);
	else if (*str == 'p')
		ft_define_push(str);
	else if ((strcmp(str, "ra") == 0) || (strcmp(str, "rb") == 0)
		|| (strcmp(str, "rr") == 0))
		ft_define_rotate(str);
	else
		ft_define_reverse_rotate(str);
}
