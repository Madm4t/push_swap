#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct stack_list
{
    int                    value;
    struct stack_list    *next;
    struct stack_list    *prev;
}    t_stack;

t_stack	*find_last_node(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

int main() {
  t_stack *a;
//  t_stack *b = NULL;
  a = malloc(sizeof(t_stack));
  a->next = malloc(sizeof(t_stack));
  a->next->next = malloc(sizeof(t_stack));
  a->value = 42;
  a->next->value = 1337;
  a->next->next->value = -21;
  a->prev = NULL;
  a->next->prev = a;
  a->next->next->prev = a->next;
  a->next->next->next = NULL;
	printf("Before:\n%d\n%d\n%d\n",a->value, a->next->value, a->next->next->value);
  rev_rotate(&a);
  printf("After:\n%d\n%d\n%d",a->value, a->next->value, a->next->next->value);
}