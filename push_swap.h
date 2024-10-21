/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:33:48 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/20 17:10:41 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	int				position;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
}					t_stack;

// UTILS
//void				ft_print_stack(t_stack *stack);
void				ft_delete_node(t_node *node);
void				ft_insert_beggining(t_node **top, int value, int position);
void				ft_insert_end(t_node **bottom, int value, int position);
void				ft_init_stack(t_node **top, t_node **bottom, int value,
						int position);
void				ft_free_stack(t_stack *stack);
int					ft_atol(const char *str, long *result);
int					ft_ascending(int a, int b);
int					ft_compare_value(const void *a, const void *b);
int					is_sorted(t_stack *stack);

// OPERATIONS
void				ft_sa(t_stack *a, int flag);
void				ft_sb(t_stack *b, int flag);
void				ft_ss(t_stack *a, t_stack *b);
void				ft_pa(t_stack *a, t_stack *b);
void				ft_pb(t_stack *b, t_stack *a);
void				ft_ra(t_stack *a, int flag);
void				ft_rb(t_stack *b, int flag);
void				ft_rr(t_stack *a, t_stack *b);
void				ft_rra(t_stack *a, int flag);
void				ft_rrb(t_stack *b, int flag);
void				ft_rrr(t_stack *a, t_stack *b);

// PARSING
int					ft_is_valid(const char *str);
int					ft_parse_int(const char *str, int *result);
int					ft_is_duplicate_in_input(int *parsed_values, int index,
						int value);
int					ft_error(int *parsed_values, char **argv, 
						int argc, int split);
int					ft_parse_and_check_input(int argc, char **argv,
						int *parsed_values, int split);
int					ft_initialize(t_stack **a, t_stack **b, int *parsed_values,
						int array_len);
void				ft_normalize_data(int *parsed_values, int len, t_stack *a);

// CHECKER
int					ft_input_is_sorted(int *parsed_values, int array_len);

// SORT
void				ft_qsort(void *base, size_t nmeb, size_t size, 
						int (compar)(const void*, const void*));
void				ft_radix(t_stack *a, t_stack *b);
void				ft_sort_less_five(t_stack *a, t_stack *b, int argc);
#endif
