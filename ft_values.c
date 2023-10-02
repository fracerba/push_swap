/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_values.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:30:43 by fracerba          #+#    #+#             */
/*   Updated: 2023/02/06 15:25:57 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_already_sorted(t_stack *stack)
{
	while (stack -> next != NULL)
	{
		if (stack -> num > stack -> next -> num)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

void	ft_two_values(t_stack **stack)
{
	if ((*stack)-> next == NULL)
		return ;
	if ((*stack)->num > (*stack)->next->num)
	{
		ft_swap(*stack, 'a');
		return ;
	}
}

void	ft_three_values(t_stack **stack)
{
	if ((*stack)->index < (*stack)->next->index)
	{
		if ((*stack)->next->index < (*stack)->next->next->index)
			return ;
		else if ((*stack)->next->index > (*stack)->next->next->index)
		{
			ft_reverse_rotate(stack, 'a');
			if ((*stack)->index > (*stack)->next->index)
				ft_swap(*stack, 'a');
		}
	}
	else if ((*stack)->index > (*stack)->next->index)
	{
		if ((*stack)->index < (*stack)->next->next->index)
			ft_swap(*stack, 'a');
		else if ((*stack)->index > (*stack)->next->next->index)
		{
			ft_rotate(stack, 'a');
			if ((*stack)->index > (*stack)->next->index)
				ft_swap(*stack, 'a');
		}
	}
}

void	ft_shift(t_stack **stack)
{
	int	low;
	int	size;

	size = get_size(*stack);
	low = ft_get_lowest(stack);
	if (low > size / 2)
	{
		while (low < size)
		{
			ft_reverse_rotate(stack, 'a');
			low++;
		}
	}
	else
	{
		while (low > 0)
		{
			ft_rotate(stack, 'a');
			low--;
		}
	}
}

void	ft_more_values(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (ft_already_sorted(*stack_a))
		return ;
	size = get_size(*stack_a);
	ft_push_most(stack_a, stack_b, size);
	ft_three_values(stack_a);
	while (*stack_b)
	{
		ft_get_target_position(stack_a, stack_b);
		ft_get_cost(stack_a, stack_b);
		ft_best_move(stack_a, stack_b);
	}
	if (!ft_already_sorted(*stack_a))
		ft_shift(stack_a);
}
