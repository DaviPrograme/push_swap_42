/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_numbers_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:26:28 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 17:53:56 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_number_is_greater_how_numbers(t_stack *a, int count_comps)
{
	int	loops;
	int	count_bigger;

	count_bigger = 0;
	loops = a->top;
	while (++loops <= a->top + count_comps)
	{
		if (a->stack_numbers[a->top] > a->stack_numbers[loops])
			++count_bigger;
	}
	return (count_bigger);
}

void	sort_two_numbers(t_stack *a)
{
	if (a->stack_numbers[a->top] > a->stack_numbers[a->top + 1])
		swap_one_stack(a, SA, 1);
}

void	sort_tree_numbers(t_stack *a)
{
	int	loops;
	int	index_higher;

	loops = a->top - 1;
	index_higher = a->top;
	while (++loops < a->top + 3)
	{
		if (a->stack_numbers[loops] > a->stack_numbers[index_higher])
			index_higher = loops;
	}
	if (index_higher == a->top)
		rotate_stack(a, RA, 1);
	else if (index_higher == a->top + 1)
		reverse_rotate_stack(a, RRA, 1);
	if (a->stack_numbers[a->top] > a->stack_numbers[a->top + 1])
		swap_one_stack(a, SA, 1);
}

void	sort_four_numbers(t_stack *a, t_stack *b)
{
	int	loops;
	int	count_bigger;

	count_bigger = 0;
	loops = a->top;
	if (top_number_is_greater_how_numbers(a, 3) == 2)
		swap_one_stack(a, SA, 1);
	push_number(a, b, PB);
	sort_tree_numbers(a);
	loops = a->top - 1;
	while (++loops < a->top + 3)
	{
		if (a->stack_numbers[loops] < b->stack_numbers[b->top])
			++count_bigger;
	}
	push_number(b, a, PA);
	if (count_bigger && count_bigger < 3)
		sort_few_numbers(a, b, count_bigger + 1);
	else if (count_bigger == 3)
		rotate_stack(a, RA, 1);
}

void	sort_five_numbers(t_stack *a, t_stack *b)
{
	int	loops;
	int	count_bigger;

	count_bigger = 0;
	while (1)
	{
		loops = top_number_is_greater_how_numbers(a, 4);
		if (loops == 2 || loops == 3)
			rotate_stack(a, RA, 1);
		else
			break ;
	}
	push_number(a, b, PB);
	sort_four_numbers(a, b);
	loops = a->top - 1;
	while (++loops < a->top + 4)
	{
		if (a->stack_numbers[loops] < b->stack_numbers[b->top])
			++count_bigger;
	}
	push_number(b, a, PA);
	if (count_bigger && count_bigger < 4)
		sort_few_numbers(a, b, count_bigger + 1);
	else if (count_bigger == 4)
		rotate_stack(a, RA, 1);
}
