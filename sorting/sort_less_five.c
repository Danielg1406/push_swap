#include "push_swap.h"

void	ft_sort_three(t_stack *a)
{
	while (!is_sorted(a))
	{
		if (a->top->position == 3 && a->top->next->position == 1)
			ft_ra(a, 1);
		else if (a->top->position == 2 && a->top->next->position == 3)
			ft_rra(a, 1);
		else
			ft_sa(a, 1);
	}
}

void	ft_sort_four(t_stack *a)
{
	printf("sort 4\n");
	printf("first a: %d\n", a->top->position);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	printf("sort 5\n");
	printf("first a: %d first b: %d\n", a->top->position, b->top->position);
}

void	ft_sort_less_five(t_stack *a, t_stack *b, int argc)
{
	if (argc == 3)
		ft_sort_three(a);
	else if (argc == 4)
		ft_sort_four(a);
	else
		ft_sort_five(a, b);
}
