/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:30:43 by fracerba          #+#    #+#             */
/*   Updated: 2023/02/06 15:26:25 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dup(char **argv)
{
	int			i;
	int			j;
	long int	k;
	long int	l;

	i = 1;
	while (argv[i])
	{
		k = ft_better_atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			l = ft_better_atoi(argv[j]);
			if (k == l)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_number(char *string)
{
	int	i;

	i = 0;
	if ((string[i] == 43 || string[i] == 45) && string[i + 1])
		i++;
	while (string[i])
	{
		if (string[i] < 48 || string[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	ft_arg_zero(char *string)
{
	int	i;

	i = 0;
	if ((string[i] == 43 || string[i] == 45) && string[i + 1])
		i++;
	while (string[i] && string[i] == 48)
		i++;
	if (string[i])
		return (0);
	return (1);
}

int	check_input(char **argv)
{
	int	i;
	int	zero;

	i = 1;
	zero = 0;
	while (argv[i])
	{
		if (!ft_check_number(argv[i]))
			return (0);
		zero = zero + ft_arg_zero(argv[i]);
		i++;
	}
	if (zero > 1)
		return (0);
	if (ft_check_dup(argv))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	if (!check_input(argv))
	{
		ft_instructions(0);
		exit(0);
	}
	stack_a = ft_init_stack(argc, argv);
	stack_b = NULL;
	size = get_size(stack_a);
	ft_set_index(stack_a, size);
	if (size <= 2)
		ft_two_values(&stack_a);
	else if (size == 3)
		ft_three_values(&stack_a);
	else if (size > 3)
		ft_more_values(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
