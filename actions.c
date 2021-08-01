/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:26:28 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 17:53:56 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_number(t_stack *origin, t_stack *destiny, char *action)
{
	if (origin->top < origin->size)
	{
		destiny->top -= 1;
		destiny->stack_numbers[destiny->top] = \
		origin->stack_numbers[origin->top];
		origin->stack_numbers[origin->top] = 0;
		origin->top += 1;
	}
	ft_putstr_fd(action, 1);
}

void	swap_one_stack(t_stack *stack, char *action, int is_swap_one)
{
	int	temp;

	if (stack->top < stack->size - 1)
	{
		temp = stack->stack_numbers[stack->top];
		stack->stack_numbers[stack->top] = stack->stack_numbers[stack->top + 1];
		stack->stack_numbers[stack->top + 1] = temp;
	}
	if (is_swap_one)
		ft_putstr_fd(action, 1);
}

void	swap_all_stacks(t_stack *a, t_stack *b)
{
	swap_one_stack(a, "", 0);
	swap_one_stack(b, "", 0);
	ft_putstr_fd(SS, 1);
}

void	rotate_stack(t_stack *stack, char *action, int is_rotate_one)
{
	int	temp;
	int	rotate;

	if (stack->top < stack->size - 1)
	{
		temp = stack->stack_numbers[stack->top];
		rotate = stack->top;
		while (++rotate <= stack->size - 1)
			stack->stack_numbers[rotate - 1] = stack->stack_numbers[rotate];
		stack->stack_numbers[rotate - 1] = temp;
	}
	if (is_rotate_one)
		ft_putstr_fd(action, 1);
}

void	rotate_all_stacks(t_stack *a, t_stack *b)
{
	rotate_stack(a, "", 0);
	rotate_stack(b, "", 0);
	ft_putstr_fd(RR, 1);
}
