/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:04:33 by mtewelde          #+#    #+#             */
/*   Updated: 2024/02/24 13:57:45 by mtewelde         ###   ########.fr       */
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
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}	t_stack_node;

char					**ft_split(char *str, char sep);

void					initiate_stack(t_stack_node **one, char **av, bool flag_ac2);
bool					error_input(char *str);
bool					check_sort(t_stack_node *stack);

int						error_repetition(t_stack_node *one, int nb);
int						ft_stack_len(t_stack_node *stack);
int						ft_stack_len(t_stack_node *stack);

static long				ft_atol(const char *str);

t_stack_node			*ft_final_node(t_stack_node *stack);
// static t_stack_node		*ft_find_largest(t_stack_node *stack);

void					sa(t_stack_node **stack_a);
void					sb(t_stack_node **stack_b);
void					ss(t_stack_node **stack_a, t_stack_node **stack_b);

void					ra(t_stack_node **stack_a);
void					rb(t_stack_node **stack_b);
void					rr(t_stack_node **stack_a, t_stack_node **stack_b);

void					rra(t_stack_node **stack_a);
void					rrb(t_stack_node **stack_b);
void					rrr(t_stack_node **stack_a, t_stack_node **stack_b);

void					tiny_sort(t_stack_node **stack_a);


void					error_free(t_stack_node **one, char **av, bool flag_ac2);
void					free_string(char **av);
void					free_stack(t_stack_node **stack);

bool					check_sort(t_stack_node *stack);

#endif