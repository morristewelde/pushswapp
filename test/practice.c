#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_stack_node
{
    int value;
    struct s_stack_node *next;
    struct s_stack_node *previous;
} t_stack_node;

t_stack_node	*ft_final_node(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int stack_len(t_stack_node *stack)
{
    int len = 0;
    while (stack)
    {
        len++;
        stack = stack->next;
    }
    return len;
}

void append_stack(t_stack_node **stack, int nb)
{
    t_stack_node    *node;
    node = malloc(sizeof(t_stack_node));
    if (node == NULL)
        return ;
    node->value = nb;
    node->next = NULL;
    node->previous = NULL;
    if (*stack == NULL)
    {
        *stack = node;
    }
    else
    {
        t_stack_node *last;
        last = *stack;
        while (last->next)
            last = last->next;
        last->next = node;
        node->previous = last;
    }
}

void print_stack(t_stack_node *stack)
{
    while (stack)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*final;
	int				len;

	len = stack_len(*stack);
	if(*stack == NULL || stack == NULL || len == 1)
		return ;
	final = ft_final_node(*stack);
	final->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	final->next->previous = final;
	final->next->next = NULL;
}

void initiate_stack(t_stack_node **a)
{
    char *av[] = {"12", "1", "45", NULL};
    int i = 0;
    while (av[i])
    {
        int nb = atoi(av[i]);
        append_stack(a, nb);
        i++;
    }
}

int main()
{
    t_stack_node *a = NULL;

    initiate_stack(&a);
    printf("Before :\n");
    print_stack(a);

    rotate(&a);
    printf("After :\n");
    print_stack(a);

    return 0;
}

// t_stack_node	*find_last_node(t_stack_node *head)
// {
// 	if (NULL == head)
// 		return (NULL);
// 	while (head->next)
// 		head = head->next;
// 	return (head);
// }

// /*
//  * Search for the last node and append 
//  * 🚨 Pay attention if the stack empty?
// */
// void	append_node(t_stack_node **stack, int nbr)
// {
// 	t_stack_node	*node;
// 	t_stack_node	*last_node;

// 	if (NULL == stack)
// 		return ;
// 	node = malloc(sizeof(t_stack_node));
// 	if (NULL == node)
// 		return ;
// 	node->next = NULL;
// 	node->value = nbr;
// 	if (NULL == *stack)
// 	{
// 		*stack = node;
// 		node->prev = NULL;
// 	}
// 	else
// 	{
// 		last_node = find_last_node(*stack);
// 		last_node->next = node;
// 		node->prev = last_node;
// 	}
// }

// /*
//  * Find the smallest value node
// */
// t_stack_node	*find_smallest(t_stack_node *stack)
// {
// 	long			smallest;
// 	t_stack_node	*smallest_node;

// 	if (NULL == stack)
// 		return (NULL);
// 	smallest = LONG_MAX;
// 	while (stack)
// 	{
// 		if (stack->value < smallest)
// 		{
// 			smallest = stack->value;
// 			smallest_node = stack;
// 		}
// 		stack = stack->next;
// 	}
// 	return (smallest_node);
// }

// /*
//  * Return the cheapest node 
//  * that is already flagged
// */
// t_stack_node	*return_cheapest(t_stack_node *stack)
// {
// 	if (NULL == stack)
// 		return (NULL);
// 	while (stack)
// 	{
// 		if (stack->cheapest)
// 			return (stack);
// 		stack = stack->next;
// 	}
// 	return (NULL);
// }

// int	stack_len(t_stack_node *stack)
// {
// 	int	count;

// 	if (NULL == stack)
// 		return (0);
// 	count = 0;
// 	while (stack)
// 	{
// 		++count;
// 		stack = stack->next;
// 	}
// 	return (count);
// }

// /*
//  *  atol, i need it to check eventual overflows
//  *  converting every string into a long value
// */
// static long	ft_atol(const char *str)
// {
// 	long	num;
// 	int		isneg;
// 	int		i;

// 	num = 0;
// 	isneg = 1;
// 	i = 0;
// 	while (str[i] && (str[i] == ' ' || str[i] == '\t'
// 			|| str[i] == '\n' || str[i] == '\r'
// 			|| str[i] == '\v' || str[i] == '\f'))
// 		i++;
// 	if (str[i] == '+')
// 		i++;
// 	else if (str[i] == '-')
// 	{
// 		isneg *= -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		num = (num * 10) + (str[i] - '0');
// 		i++;
// 	}
// 	return (num * isneg);
// }

// /*
//  * Create the stack with the command line values
//  * Checks are embedded in the creation itslef
//  * 		~Duplicate values
//  * 		~Over|Underflow
//  * 		~Syntax errors
//  *
//  * 	🏁 Flag is useful cause if true, i have the argv in the HEAP to free
//  *
// */
// void	stack_init(t_stack_node **a, char **argv, bool flag_argc_2)
// {
// 	long	nbr;
// 	int		i;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		if (error_syntax(argv[i]))
// 			error_free(a, argv, flag_argc_2);
// 		nbr = ft_atol(argv[i]);
// 		if (nbr > INT_MAX || nbr < INT_MIN)
// 			error_free(a, argv, flag_argc_2);
// 		if (error_repetition(*a, (int)nbr))
// 			error_free(a, argv, flag_argc_2);
// 		append_node(a, (int)nbr);
// 		++i;
// 	}
// 	if (flag_argc_2)
// 		free_matrix(argv);
// }


// void	set_current_position(t_stack_node *stack)
// {
// 	int	i;
// 	int	centerline;

// 	i = 0;
// 	if (NULL == stack)
// 		return ;
// 	centerline = stack_len(stack) / 2;
// 	while (stack)
// 	{
// 		stack->current_position = i;
// 		if (i <= centerline)
// 			stack->above_median = true;
// 		else
// 			stack->above_median = false;
// 		stack = stack->next;
// 		++i;
// 	}
// }

// /*
//  *	Best match is..
//  *   | "The Smallest-bigger value" |
//  *
//  *  if no node is Bigger, best_match is the Smallest node.
//  *  TLDR 
//  *  With this function every node in b gets its target node in a
// */
// static void	set_target_node(t_stack_node *a,
// 							t_stack_node *b)
// {
// 	t_stack_node	*current_a;
// 	t_stack_node	*target_node;
// 	long			best_match_index;

// 	while (b)
// 	{
// 		best_match_index = LONG_MAX;
// 		current_a = a;
// 		while (current_a)
// 		{
// 			if (current_a->value > b->value
// 				&& current_a->value < best_match_index)
// 			{
// 				best_match_index = current_a->value;
// 				target_node = current_a;
// 			}
// 			current_a = current_a->next;
// 		}
// 		if (LONG_MAX == best_match_index)
// 			b->target_node = find_smallest(a);
// 		else
// 			b->target_node = target_node;
// 		b = b->next;
// 	}
// }

// /*
//  * Set the prices to push the node
//  * from b -> a
//  * The price checks for the relative positions in the stack
//  * for every node, setting the respective price
// */
// void	set_price(t_stack_node *a, t_stack_node *b)
// {
// 	int	len_a;
// 	int	len_b;

// 	len_a = stack_len(a);
// 	len_b = stack_len(b);
// 	while (b)
// 	{
// 		b->push_price = b->current_position;
// 		if (!(b->above_median))
// 			b->push_price = len_b - (b->current_position);
// 		if (b->target_node->above_median)
// 			b->push_price += b->target_node->current_position;
// 		else
// 			b->push_price += len_a - (b->target_node->current_position);
// 		b = b->next;
// 	}
// }

// /*
//  * Flag the cheapest node in the current
//  * stacks configurations
// */
// void	set_cheapest(t_stack_node *b)
// {
// 	long			best_match_value;
// 	t_stack_node	*best_match_node;

// 	if (NULL == b)
// 		return ;
// 	best_match_value = LONG_MAX;
// 	while (b)
// 	{
// 		if (b->push_price < best_match_value)
// 		{
// 			best_match_value = b->push_price;
// 			best_match_node = b;
// 		}
// 		b = b->next;
// 	}
// 	best_match_node->cheapest = true;
// }

// /*
//  * All the necessary values to make the push
//  * 		~Relative Positions
//  * 		~Target node, the b node to make emerge
//  * 		~Price for every configuration
//  * 		~Cheapest in the current configuration
// */
// void	init_nodes(t_stack_node *a, t_stack_node *b)
// {
// 	set_current_position(a);
// 	set_current_position(b);
// 	set_target_node(a, b);
// 	set_price(a, b);
// 	set_cheapest(b);
// }


// /*
//  * Loop decays once
//  * 		~cheapest_node tops is a
//  * 		~relative target_node tops in b
// */
// static void	rotate_both(t_stack_node **a,
// 						t_stack_node **b,
// 						t_stack_node *cheapest_node)
// {
// 	while (*a != cheapest_node->target_node
// 		&& *b != cheapest_node)
// 		rr(a, b, false);
// 	set_current_position(*a);
// 	set_current_position(*b);
// }

// static void	reverse_rotate_both(t_stack_node **a,
// 								t_stack_node **b,
// 								t_stack_node *cheapest_node)
// {
// 	while (*a != cheapest_node->target_node
// 		&& *b != cheapest_node)
// 		rrr(a, b, false);
// 	set_current_position(*a);
// 	set_current_position(*b);
// }

// /*
//  * Conclude the rotation of the stacks 
// */
// void	finish_rotation(t_stack_node **stack,
// 							t_stack_node *top_node,
// 							char stack_name)
// {
// 	while (*stack != top_node)
// 	{
// 		if (stack_name == 'a')
// 		{
// 			if (top_node->above_median)
// 				ra(stack, false);
// 			else
// 				rra(stack, false);
// 		}
// 		else if (stack_name == 'b')
// 		{
// 			if (top_node->above_median)
// 				rb(stack, false);
// 			else
// 				rrb(stack, false);
// 		}	
// 	}
// }

// /*
//  * Move the node from 'b' to 'a'
//  * with the metadata available in the node
//  * 1)Make the target nodes emerge
//  * 2)push in A
// */
// static void	move_nodes(t_stack_node **a, t_stack_node **b)
// {
// 	t_stack_node	*cheapest_node;

// 	cheapest_node = return_cheapest(*b);
// 	if (cheapest_node->above_median
// 		&& cheapest_node->target_node->above_median)
// 		rotate_both(a, b, cheapest_node);
// 	else if (!(cheapest_node->above_median)
// 		&& !(cheapest_node->target_node->above_median))
// 		reverse_rotate_both(a, b, cheapest_node);
// 	finish_rotation(b, cheapest_node, 'b');
// 	finish_rotation(a, cheapest_node->target_node, 'a');
// 	pa(a, b, false);
// }

// /*
//  * ~Push all nodes in B 
//  * ~For every configuration choose the "cheapest_node"
//  * ~Push everything back in A in order
// */
// void	push_swap(t_stack_node **a, t_stack_node **b)
// {
// 	t_stack_node	*smallest;
// 	int				len_a;

// 	len_a = stack_len(*a);
// 	if (len_a == 5)
// 		handle_five(a, b);
// 	else
// 	{
// 		while (len_a-- > 3)
// 			pb(b, a, false);
// 	}
// 	tiny_sort(a);
// 	while (*b)
// 	{
// 		init_nodes(*a, *b);
// 		move_nodes(a, b);
// 	}
// 	set_current_position(*a);
// 	smallest = find_smallest(*a);
// 	if (smallest->above_median)
// 		while (*a != smallest)
// 			ra(a, false);
// 	else
// 		while (*a != smallest)
// 			rra(a, false);
// }


// /*
//  * Push a node to the top from src to dest
//  * 🚨 attention If stack empty (i.e. NULL)
// */

// static void	push(t_stack_node **dest, t_stack_node **src)
// {
// 	t_stack_node	*node_to_push;

// 	if (NULL == *src)
// 		return ;
// 	node_to_push = *src;
// 	*src = (*src)->next;
// 	if (*src)
// 		(*src)->prev = NULL;
// 	node_to_push->prev = NULL;
// 	if (NULL == *dest)
// 	{
// 		*dest = node_to_push;
// 		node_to_push->next = NULL;
// 	}
// 	else
// 	{
// 		node_to_push->next = *dest;
// 		node_to_push->next->prev = node_to_push;
// 		*dest = node_to_push;
// 	}
// }

// void	pa(t_stack_node **a, t_stack_node **b, bool checker)
// {
// 	push(a, b);
// 	if (!checker)
// 		write(1, "pa\n", 3);
// }

// void	pb(t_stack_node **b, t_stack_node **a, bool checker)
// {
// 	push(b, a);
// 	if (!checker)
// 		write(1, "pb\n", 3);
// }
