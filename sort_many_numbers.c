/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:26:28 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 17:53:56 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	classification_stack_main_to_radix(t_stack *main, t_stack *radix)
{
	int	loops;
	int	count_biggers;
	int	count_classifieds;

	count_classifieds = 0;
	while (count_classifieds < main->size)
	{
		loops = -1;
		count_biggers = 0;
		while (++loops < main->size)
		{
			if (main->stack_numbers[count_classifieds] > \
					main->stack_numbers[loops])
				++count_biggers;
		}
		radix->stack_numbers[count_classifieds] = count_biggers;
		++count_classifieds;
	}
}

int	check_if_rest_is_ordered(t_stack *stack)
{
	int	loops;

	loops = stack->top - 1;
	while (++loops < stack->size - 1)
	{
		if (stack->stack_numbers[loops + 1] - stack->stack_numbers[loops] != 1)
			return (0);
	}
	return (1);
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int	loops;
	int	count_bit;

	count_bit = 1;
	while (!(check_if_numbers_ordered(a)))
	{
		loops = -1;
		while (++loops < a->size)
		{
			if ((a->stack_numbers[a->top] & count_bit))
				rotate_stack(a, RA, 1);
			else
				push_number(a, b, PB);
			if (check_if_rest_is_ordered(a))
				break ;
		}
		while (b->top < b->size)
			push_number(b, a, PA);
		count_bit *= 2;
	}
}

void	sort_many_numbers(t_stack *a, t_stack *b, t_stack *radix)
{
	if (check_if_numbers_ordered(a))
		return ;
	classification_stack_main_to_radix(a, radix);
	sort_radix(radix, b);
}
