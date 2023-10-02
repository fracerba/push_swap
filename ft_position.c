/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:09:07 by fracerba          #+#    #+#             */
/*   Updated: 2023/02/09 16:09:09 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp -> pos = i;
		tmp = tmp -> next;
		i++;
	}
}

int	ft_get_lowest(t_stack **stack)
{
	t_stack	*tmp;
	int		pos;
	int		idx;

	tmp = *stack;
	ft_get_position(stack);
	pos = tmp->pos;
	idx = 2147483647;
	while (tmp)
	{
		if (tmp ->index < idx)
		{
			pos = tmp ->pos;
			idx = tmp ->index;
		}
		tmp = tmp->next;
	}
	return (pos);
}

int	ft_get_target(t_stack **stack_a, int b_index, int pos, int idx)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp -> index < idx && tmp -> index > b_index)
		{
			idx = tmp -> index;
			pos = tmp -> pos;
		}
		tmp = tmp -> next;
	}
	if (idx != 2147483647)
		return (pos);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp -> index < idx)
		{
			idx = tmp -> index;
			pos = tmp -> pos;
		}
		tmp = tmp -> next;
	}
	return (pos);
}

void	ft_get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack_b;
	ft_get_position(stack_a);
	ft_get_position(stack_b);
	i = 0;
	while (tmp)
	{
		i = ft_get_target(stack_a, tmp -> index, i, 2147483647);
		tmp -> target = i;
		tmp = tmp -> next;
	}
}
