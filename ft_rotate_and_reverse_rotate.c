/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_and_reverse_rotate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:10:38 by fracerba          #+#    #+#             */
/*   Updated: 2023/02/09 16:10:42 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack, char s)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	while (tmp && tmp -> next)
		tmp = tmp -> next;
	tail = tmp;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp -> next = NULL;
	tail -> next = tmp;
	if (s == 'a')
		ft_instructions(4);
	else if (s == 'b')
		ft_instructions(5);
}

void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, 'c');
	ft_rotate(stack_b, 'c');
	ft_instructions(6);
}

void	ft_reverse_rotate(t_stack **stack, char s)
{
	t_stack	*tmp;
	t_stack	*before_tail;
	t_stack	*tail;

	tmp = *stack;
	while (tmp && tmp -> next)
		tmp = tmp -> next;
	tail = tmp;
	tmp = *stack;
	while (tmp && tmp -> next && tmp -> next -> next)
		tmp = tmp -> next;
	before_tail = tmp;
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail -> next = NULL;
	if (s == 'a')
		ft_instructions(7);
	else if (s == 'b')
		ft_instructions(8);
}

void	ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a, 'c');
	ft_reverse_rotate(stack_b, 'c');
	ft_instructions(9);
}
