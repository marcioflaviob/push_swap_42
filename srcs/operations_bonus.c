/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:02:14 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/08 23:26:42 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*swap_b(t_stack *stack)
{
	t_stack	*next;

	next = stack->next;
	stack->prev = next;
	next->prev = NULL;
	if (next->next)
	{
		stack->next = next->next;
		next->next->prev = stack;
	}
	else
		stack->next = NULL;
	next->next = stack;
	next->index = 0;
	stack->index = 1;
	return (next);
}

t_stack	*rotate_b(t_stack *stack)
{
	t_stack	*last;
	t_stack	*second;

	stack = get_first(stack);
	last = get_last(stack);
	second = stack->next;
	last->next = stack;
	stack->prev = last;
	second->prev = NULL;
	stack->next = NULL;
	fix_index(second);
	return (second);
}

t_stack	*reverse_rotate_b(t_stack *stack)
{
	t_stack	*last;

	stack = get_first(stack);
	last = get_last(stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = stack;
	stack->prev = last;
	fix_index(last);
	return (last);
}

void	null_setter(t_stack **a, t_stack **a_second)
{
	(*a)->prev = NULL;
	(*a)->next = NULL;
	(*a_second)->prev = NULL;
}

t_stack	*push_b(t_stack *a, t_stack *b)
{
	t_stack	*a_second;

	a = get_first(a);
	a_second = a->next;
	if (!b)
	{
		b = a;
		null_setter(&a, &a_second);
		fix_both(a_second, b);
		return (b);
	}
	else
	{
		b = get_first(b);
		if (a == b)
			return (a);
		if (a_second)
			a_second->prev = NULL;
		a->next = b;
		b->prev = a;
	}
	if (!a_second)
		return (a);
	fix_both(a_second, b);
	return (a_second);
}
