/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:24:08 by fracerba          #+#    #+#             */
/*   Updated: 2023/02/06 15:24:12 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack -> next;
		i++;
	}
	return (i);
}

void	free_stack(t_stack **stack)
{
	t_stack	*del;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		del = (*stack)->next;
		free(*stack);
		*stack = del;
	}
	*stack = NULL;
}

t_stack	*ft_stack_new(long int nb)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->num = (int)nb;
	new->index = 0;
	new->pos = -1;
	new->target = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	ft_stack_add_bottom(t_stack **stack, long int num)
{
	t_stack	*new;
	t_stack	*tail;
	t_stack	*tmp;

	new = ft_stack_new(num);
	tmp = *stack;
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	while (tmp && tmp -> next)
		tmp = tmp -> next;
	tail = tmp;
	tail -> next = new;
}

t_stack	*ft_init_stack(int argc, char **argv)
{
	int			i;
	long int	num;
	t_stack		*stack;

	i = 1;
	num = 0;
	stack = NULL;
	while (i < argc)
	{
		num = ft_better_atoi(argv[i]);
		if (num < -2147483648 || num > 2147483647)
		{
			ft_instructions(0);
			free_stack(&stack);
			exit(0);
		}
		if (i == 1)
			stack = ft_stack_new(num);
		else
			ft_stack_add_bottom(&stack, num);
		i++;
	}
	return (stack);
}
