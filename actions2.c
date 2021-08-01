/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:26:28 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 17:53:56 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_stack *stack, char *action, int is_rotate_one)
{
	int	temp;
	int	rotate;

	if (stack->top < stack->size - 1)
	{
		temp = stack->stack_numbers[stack->size - 1];
		rotate = stack->size;
		while (--rotate > stack->top)
			stack->stack_numbers[rotate] = stack->stack_numbers[rotate - 1];
		stack->stack_numbers[stack->top] = temp;
	}
	if (is_rotate_one)
		ft_putstr_fd(action, 1);
}

void	reverse_rotate_all_stacks(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a, "", 0);
	reverse_rotate_stack(b, "", 0);
	ft_putstr_fd(RRR, 1);
}
