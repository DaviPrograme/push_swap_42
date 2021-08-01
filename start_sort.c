/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:26:28 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 17:53:56 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initialize_stack(int count_elements, \
			char **numbers, int flag_main_stack)
{
	t_stack	*stack;
	int		loops;

	loops = -1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error(3);
	stack->stack_numbers = (int *)ft_calloc(sizeof(int), count_elements);
	if (!stack->stack_numbers)
		error(3);
	while (flag_main_stack && ++loops < count_elements - 1)
	{
		stack->stack_numbers[loops] = ft_atoi(numbers[loops + 1]);
		check_if_ocurred_overflow(stack->stack_numbers[loops], \
				numbers[loops + 1]);
	}
	stack->size = count_elements - 1;
	if (flag_main_stack)
		stack->top = 0;
	else
		stack->top = count_elements - 1;
	return (stack);
}

void	clean_memory(t_stack *a, t_stack *b, t_stack *c)
{
	free(a->stack_numbers);
	free(a);
	free(b->stack_numbers);
	free(b);
	free(c->stack_numbers);
	free(c);
}

void	start_sort_numbers(int count_numbers, char **numbers)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*aux_radix;

	stack_a = initialize_stack(count_numbers, numbers, 1);
	stack_b = initialize_stack(count_numbers, numbers, 0);
	aux_radix = initialize_stack(count_numbers, numbers, 1);
	if (count_numbers - 1 <= 5)
		sort_few_numbers(stack_a, stack_b, stack_a->size);
	else
		sort_many_numbers(stack_a, stack_b, aux_radix);
	clean_memory(stack_a, stack_b, aux_radix);
}
