/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:35:45 by fracerba          #+#    #+#             */
/*   Updated: 2023/02/06 15:26:42 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

int			ft_already_sorted(t_stack *stack);
void		ft_two_values(t_stack **stack);
void		ft_three_values(t_stack **stack);
void		ft_shift(t_stack **stack);
void		ft_more_values(t_stack **stack_a, t_stack **stack_b);

void		ft_instructions(int i);
long int	ft_better_atoi(char *string);
void		ft_set_index(t_stack *stack, int size);
void		ft_push_most(t_stack **stack_a, t_stack **stack_b, int size);

int			ft_check_dup(char **argv);
int			ft_check_number(char *string);
int			ft_arg_zero(char *string);
int			check_input(char **argv);

int			get_size(t_stack *stack);
void		free_stack(t_stack **stack);
t_stack		*ft_stack_new(long int nb);
void		ft_stack_add_bottom(t_stack **stack, long int num);
t_stack		*ft_init_stack(int argc, char **argv);

void		ft_swap(t_stack *stack, char s);
void		ft_swap_both(t_stack *stack_a, t_stack *stack_b);
void		ft_push_to(t_stack **stack_a, t_stack **stack_b, char c);

void		ft_rotate(t_stack **stack, char s);
void		ft_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		ft_reverse_rotate(t_stack **stack, char s);
void		ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

void		ft_get_position(t_stack **stack);
int			ft_get_lowest(t_stack **stack);
int			ft_get_target(t_stack **stack_a, int b_index, int pos, int idx);
void		ft_get_target_position(t_stack **stack_a, t_stack **stack_b);

int			ft_abs(int i);
void		ft_get_cost(t_stack **stack_a, t_stack **stack_b);
void		ft_do_rotate(t_stack **stack, int *cost, char c);
void		ft_move(t_stack **stack_a, t_stack **stack_b,
				int cost_a, int cost_b);
void		ft_best_move(t_stack **stack_a, t_stack **stack_b);

#endif
