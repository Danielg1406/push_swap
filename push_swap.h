/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:33:48 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/10/04 17:48:15 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int			data;
	int			position;
	struct s_node		*next;
	struct s_node		*previous;
}				t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
}			t_stack;
#endif
