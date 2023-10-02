/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:55:02 by fracerba          #+#    #+#             */
/*   Updated: 2023/02/20 09:55:04 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}

void	ft_get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_size(tmp_a);
	size_b = get_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > (size_b / 2))
			tmp_b->cost_b = -(size_b - tmp_b->pos);
		tmp_b->cost_a = tmp_b->target;
		if (tmp_b->target > (size_a / 2))
			tmp_b->cost_a = -(size_a - tmp_b->target);
		tmp_b = tmp_b->next;
	}
}

void	ft_do_rotate(t_stack **stack, int *cost, char c)
{
	while (*cost != 0)
	{
		if (*cost > 0)
		{
			if (c == 'a')
				ft_rotate(stack, 'a');
			else if (c == 'b')
				ft_rotate(stack, 'b');
			(*cost)--;
		}
		else if (*cost < 0)
		{
			if (c == 'a')
				ft_reverse_rotate(stack, 'a');
			else if (c == 'b')
				ft_reverse_rotate(stack, 'b');
			(*cost)++;
		}
	}
}

void	ft_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		cost_a--;
		cost_b--;
		ft_rotate_both(stack_a, stack_b);
	}
	while (cost_a < 0 && cost_b < 0)
	{
		cost_a++;
		cost_b++;
		ft_reverse_rotate_both(stack_a, stack_b);
	}
	ft_do_rotate(stack_a, &cost_a, 'a');
	ft_do_rotate(stack_b, &cost_b, 'b');
	ft_push_to(stack_a, stack_b, 'a');
}

void	ft_best_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cost_a;
	int		cost_b;
	int		best;

	tmp = *stack_b;
	best = 2147483647;
	while (tmp)
	{
		if (ft_abs(best) > ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b))
		{
			best = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	ft_move(stack_a, stack_b, cost_a, cost_b);
}
