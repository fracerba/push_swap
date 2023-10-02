/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_and_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:10:22 by fracerba          #+#    #+#             */
/*   Updated: 2023/02/09 16:10:25 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack, char s)
{
	int	tmp;

	if (!stack || !stack -> next)
		return ;
	tmp = stack -> next -> num;
	stack -> next -> num = stack -> num;
	stack -> num = tmp;
	tmp = stack -> next -> index;
	stack -> next -> index = stack -> index;
	stack -> index = tmp;
	if (s == 'a')
		ft_instructions(1);
	else if (s == 'b')
		ft_instructions(2);
}

void	ft_swap_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a, 'c');
	ft_swap(stack_b, 'c');
	ft_instructions(3);
}

void	ft_push_to(t_stack **stack_2, t_stack **stack_1, char c)
{
	t_stack	*tmp;

	if (!*stack_1)
		return ;
	tmp = (*stack_1)->next;
	(*stack_1)-> next = *stack_2;
	*stack_2 = *stack_1;
	*stack_1 = tmp;
	if (c == 'a')
		ft_instructions(10);
	else if (c == 'b')
		ft_instructions(11);
}
