#include "push_swap.h"

int	main(void)
{
	t_stack *a;
	t_stack *b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));

	a->top = NULL;
	a->bottom = NULL;
	b->top = NULL;
	b->bottom = NULL;

	ft_init_stack(&a->top, &a->bottom, 4);
	ft_init_stack(&b->top, &b->bottom, 8);

	ft_insert_beggining(&a->top, 3);
	ft_insert_beggining(&a->top, 2);
	ft_insert_beggining(&a->top, 1);

	ft_insert_beggining(&b->top, 7);
	ft_insert_beggining(&b->top, 6);
	ft_insert_beggining(&b->top, 5);


	printf("stack a \n");
	ft_print_stack(a);
	printf("stack b \n");
	ft_print_stack(b);

	ft_ra(a);
	ft_rb(b);
	ft_rr(a, b);

	printf("new stack a\n");
	ft_print_stack(a);
	printf("new stack b\n");
	ft_print_stack(b);
	return(0);
}
