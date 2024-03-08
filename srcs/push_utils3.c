/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:34:58 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/08 17:14:14 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_by_index(t_stack *stack, int index)
{
	t_stack	*result;

	stack = get_first(stack);
	while (stack->next)
	{
		if (stack->index == index)
		{
			result = stack;
			return (result);
		}
		stack = stack->next;
	}
	if (stack->index == index)
	{
		result = stack;
		return (result);
	}
	return (NULL);
}

t_stack	*get_by_val(t_stack *stack, int val)
{
	t_stack	*result;

	stack = get_first(stack);
	while (stack->next)
	{
		if (stack->val == val)
		{
			result = stack;
			return (result);
		}
		stack = stack->next;
	}
	if (stack->val == val)
	{
		result = stack;
		return (result);
	}
	return (NULL);
}

t_stack	*get_first(t_stack *node)
{
	int	i;

	i = 0;
	while (node->prev)
		node = node->prev;
	return (node);
}

t_stack	*get_last(t_stack *stack)
{
	stack = get_first(stack);
	fix_index(stack);
	return (get_by_index(stack, stack_size(stack) - 1));
}

void	get_targets(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		size;
	t_stack	*temp;

	i = 0;
	j = 0;
	a = get_first(a);
	b = get_first(b);
	size = stack_size(a);
	while (i < size)
	{
		temp = get_by_index(a, i);
		temp->target = get_biggest_smaller(b, temp->val);
		i++;
	}
}
