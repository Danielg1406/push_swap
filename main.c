/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:42:26 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/09 13:53:06 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{	
	int	i = 0;
	int	*parsed_values;
	t_stack *a;
	t_stack *b;

	if(argc < 2)
	{
		ft_putendl_fd("", 2);
		return (1);
	}
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	a->top = NULL;
	a->bottom = NULL;
	b->top = NULL;
	b->bottom = NULL;

	parsed_values = malloc((argc - 1) * sizeof(int));
	if (!parsed_values || !ft_parse_and_check_input(argc, argv, parsed_values))
		return (1);
	printf("passed check\n");
	while (i < argc - 1)
	{
		printf("%d\n", parsed_values[i]);
		i++;
	}
	free(parsed_values);
	return (0);
}
