/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:04:36 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/22 23:14:43 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

//checking if the arguments passed are valid numbers, 
//check repetition of the numbers
//check if sorted or not
int			check_sorted(t_stack **lst);
int			valid_av(char **av);
int			check_repetition(t_stack *stack, int nb);

// create single satck, append new stack to a
// creating (initializing) stacks
t_stack		*create_stack(int n);
void		append_stack(t_stack **stack, t_stack *tmp);
int			ft_stack_len(t_stack *stack);
t_stack		*ft_last_stack(t_stack *stack);
t_stack		**initialize(char **av);

//set the index by the length of the stack
//the smallest node setted to 1 the the biggest to the length of the stack
void		set_index(t_stack **a);
t_stack		*get_max(t_stack **stack);

//if the argument is 1 we split it andd other utils (modified)
char		**ft_split(char *s, char c);
long long	ft_atol(char *str);
void		free_str(char **p);
void		ft_error(void);
void		free_stack(t_stack **stack);

//swap functions
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

//push functions
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);

//rotate functions
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

//reverse rotate functions
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

//sorting functions
void		sort_three(t_stack **lst);
void		sort_four(t_stack **a, t_stack **b);
void		sort_five(t_stack **a, t_stack **b);
void		sort_big(t_stack **a, t_stack **b);

#endif
