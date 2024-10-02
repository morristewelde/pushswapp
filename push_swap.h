/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:49:35 by mtewelde          #+#    #+#             */
/*   Updated: 2024/07/08 14:29:24 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	bool				above_median;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}	t_stack_node;

bool				check_sort(t_stack_node *stack);

int					ft_stack_len(t_stack_node *stack);
static long			ft_atol(const char *str);

static	t_stack_node	*ft_find_largest(t_stack_node *stack);

static t_stack_node	*ft_find_smallest(t_stack_node *stack);
t_stack_node		*ft_final_node(t_stack_node *stack);

void				free_stack(t_stack_node **stack);
void				free_string(char **av);
void				error_free(t_stack_node **a, char **av, bool flag_ac2);
void				initiate_stack(t_stack_node **a, char **av, bool flag_ac2);
void				print_stack(t_stack_node *stack);
void				finish_rotation(t_stack_node **stack, t_stack_node *top_node, char stack_name);


static void			swap(t_stack_node **stack);
static void			rotate(t_stack_node **stack);
static void			reverse_rotate(t_stack_node **stack);
static void			push(t_stack_node **dest, t_stack_node **src);

void				sa(t_stack_node **stack_a);
void				ra(t_stack_node **stack_a);
void				rb(t_stack_node **stack_b);
void				rra(t_stack_node **stack_a);
void				rrb(t_stack_node **stack_b);
void				pb(t_stack_node **b, t_stack_node **a);
void				pa(t_stack_node **a, t_stack_node **b);

void				tiny_sort(t_stack_node **stack_a);

char				**ft_split(char *str, char sep);

#endif
