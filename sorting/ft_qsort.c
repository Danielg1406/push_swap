/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:54:19 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/12 13:52:19 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(void *a, void *b, size_t size)
{
	size_t			i;
	unsigned char	temp;
	unsigned char	*p;
	unsigned char	*q;

	i = 0;
	p = a;
	q = b;
	while (i < size)
	{
		temp = p[i];
		p[i] = q[i];
		q[i] = temp;
		i++;
	}
}

int	ft_partition(void *base, size_t nmeb, size_t size, 
		int (*compar)(const void *, const void *))
{
	char	*arr;
	size_t	pivot_index;
	size_t	i;
	size_t	j;

	arr = (char *)base;
	pivot_index = nmeb - 1;
	i = 0;
	j = 0;
	while (j < nmeb - 1)
	{
		if (compar(arr + j * size, arr + pivot_index * size) < 0)
		{
			ft_swap(arr + i * size, arr + j * size, size);
			i++;
		}
		j++;
	}
	ft_swap(arr + i * size, arr + pivot_index * size, size);
	return (i);
}

void	ft_qsort(void *base, size_t nmeb, size_t size, 
		int (*compar)(const void *, const void *))
{
	int	pivot_index;

	if (nmeb <= 1)
		return ;
	pivot_index = ft_partition(base, nmeb, size, compar);
	ft_qsort(base, pivot_index, size, compar);
	ft_qsort((char *)base + (pivot_index + 1) * size, 
		nmeb - pivot_index - 1, size, compar);
}
