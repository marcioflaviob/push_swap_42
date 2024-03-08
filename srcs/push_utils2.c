/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:10:37 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/28 19:11:31 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	stack = get_first(stack);
	fix_index(stack);
	check_mid(stack);
	while (stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	int	counter;

	counter = 1;
	stack = get_first(stack);
	while (stack->next)
	{
		counter++;
		stack = stack->next;
	}
	return (counter);
}

void	fix_index(t_stack *stack)
{
	int	i;

	i = 0;
	stack = get_first(stack);
	while (stack->next)
	{
		stack->index = i++;
		stack = stack->next;
	}
	stack->index = i;
}

void	fix_both(t_stack *a, t_stack *b)
{
	fix_index(a);
	fix_index(b);
}

int	get_big_index(t_stack *stack)
{
	int	index;
	int	big;

	stack = get_first(stack);
	big = stack->val;
	index = stack->index;
	while (stack->next)
	{
		if (stack->next->val > big)
		{
			big = stack->next->val;
			index = stack->next->index;
		}
		stack = stack->next;
	}
	return (index);
}
