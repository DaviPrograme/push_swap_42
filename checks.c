/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:26:28 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 17:53:56 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_they_are_numbers(char **numbers)
{
	int	loop_char;
	int	loop_string;

	loop_string = 0;
	while (numbers[++loop_string])
	{
		loop_char = -1;
		while (numbers[loop_string][++loop_char])
		{
			if (loop_char == 0 && numbers[loop_string][loop_char] == '-' && \
				ft_isdigit(numbers[loop_string][loop_char + 1]))
				continue ;
			else if (ft_isdigit(numbers[loop_string][loop_char]))
				continue ;
			error(1);
		}
	}
}

void	check_if_duplicate_elements(char **elements)
{
	int	focus;
	int	focus_len;
	int	loops;

	focus = 0;
	while (elements[++focus])
	{
		focus_len = ft_strlen(elements[focus]);
		loops = 0;
		while (elements[++loops])
		{
			if (focus == loops)
				continue ;
			if (focus_len != (int)ft_strlen(elements[loops]))
				continue ;
			if (ft_memcmp(elements[focus], elements[loops], focus_len))
				continue ;
			error(2);
		}
	}
}

void	check_if_ocurred_overflow(int number, char *string)
{
	char	*str_number;

	str_number = ft_itoa(number);
	if (!str_number)
		error(3);
	if ((ft_strlen(str_number) != ft_strlen(string)) || \
			(ft_memcmp(str_number, string, ft_strlen(str_number))))
	{
		free(str_number);
		error(4);
	}
	free(str_number);
}

int	check_if_numbers_ordered(t_stack *main)
{
	int	loops;

	loops = 0;
	if (main->top != 0)
		return (0);
	while (loops < main->size - 1)
	{
		if (main->stack_numbers[loops + 1] <= main->stack_numbers[loops])
			return (0);
		++loops;
	}
	return (1);
}
