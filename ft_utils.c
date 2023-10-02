/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:24:22 by fracerba          #+#    #+#             */
/*   Updated: 2023/02/06 15:24:25 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_instructions(int i)
{
	if (i == 0)
		ft_printf("Error\n");
	else if (i == 1)
		ft_printf("sa\n");
	else if (i == 2)
		ft_printf("sb\n");
	else if (i == 3)
		ft_printf("ss\n");
	else if (i == 4)
		ft_printf("ra\n");
	else if (i == 5)
		ft_printf("rb\n");
	else if (i == 6)
		ft_printf("rr\n");
	else if (i == 7)
		ft_printf("rra\n");
	else if (i == 8)
		ft_printf("rrb\n");
	else if (i == 9)
		ft_printf("rrr\n");
	else if (i == 10)
		ft_printf("pa\n");
	else if (i == 11)
		ft_printf("pb\n");
	return ;
}

long int	ft_better_atoi(char *string)
{
	long int	nb;
	int			s;
	int			i;

	nb = 0;
	i = 0;
	s = 1;
	if (string[i] == 43 || string[i] == 45)
	{
		if (string[i] == 45)
			s = -s;
		i++;
	}
	while (string[i] >= 48 && string[i] <= 57)
	{
		nb = (nb * 10) + (string[i] - 48);
		i++;
	}
	return (nb * s);
}

void	ft_set_index(t_stack *stack, int size)
{
	int		nb;
	t_stack	*tmp;
	t_stack	*high;

	while (size > 0)
	{
		nb = -2147483648;
		tmp = stack;
		high = NULL;
		while (tmp)
		{
			if (tmp->num == -2147483648 && tmp->index == 0)
				tmp->index = 1;
			if (tmp->num > nb && tmp->index == 0)
			{
				nb = tmp->num;
				high = tmp;
			}
			tmp = tmp->next;
		}
		if (high)
			high->index = size;
		size--;
	}
}

void	ft_push_most(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	p;
	int	i;

	i = 0;
	p = 0;
	if (size > 6)
	{
		while (i < size && p < (size / 2))
		{
			if ((*stack_a)-> index <= (size / 2))
			{
				ft_push_to(stack_b, stack_a, 'b');
				p++;
			}
			else
				ft_rotate(stack_a, 'a');
			i++;
		}
	}
	while (size > p + 3)
	{
		ft_push_to(stack_b, stack_a, 'b');
		p++;
	}
}
