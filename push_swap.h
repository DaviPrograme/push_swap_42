/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:26:28 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 17:53:56 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

typedef struct s_stack
{
	int	top;
	int	size;
	int	*stack_numbers;
}		t_stack;

void	error(int id_erro);
void	start_sort_numbers(int count_numbers, char **numbers);
void	push_number(t_stack *origin, t_stack *destiny, char *action);
void	swap_one_stack(t_stack *stack, char *action, int is_swap_one);
void	swap_all_stacks(t_stack *a, t_stack *b);
void	rotate_stack(t_stack *stack, char *action, int is_rotate_one);
void	rotate_all_stacks(t_stack *a, t_stack *b);
void	reverse_rotate_stack(t_stack *stack, char *action, int is_rotate_one);
void	reverse_rotate_all_stacks(t_stack *a, t_stack *b);
void	sort_few_numbers(t_stack *a, t_stack *b, int size_stack);
void	sort_two_numbers(t_stack *a);
void	sort_tree_numbers(t_stack *a);
void	sort_four_numbers(t_stack *a, t_stack *b);
void	sort_five_numbers(t_stack *a, t_stack *b);
int		check_if_numbers_ordered(t_stack *main);
void	check_if_they_are_numbers(char **numbers);
void	check_if_duplicate_elements(char **elements);
void	check_if_ocurred_overflow(int number, char *string);
void	sort_many_numbers(t_stack *a, t_stack *b, t_stack *radix);

#endif
