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
