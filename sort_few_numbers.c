/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:26:28 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 17:53:56 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_few_numbers(t_stack *a, t_stack *b, int size_stack)
{
	if (check_if_numbers_ordered(a))
		return ;
	else if (size_stack == 2)
		sort_two_numbers(a);
	else if (size_stack == 3)
		sort_tree_numbers(a);
	else if (size_stack == 4)
		sort_four_numbers(a, b);
	else if (size_stack == 5)
		sort_five_numbers(a, b);
}
