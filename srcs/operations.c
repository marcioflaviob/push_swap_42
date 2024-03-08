/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:25:11 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/08 23:41:14 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//int type: 0 for stack_a and 1 for stack_b and 2 for both operations
t_stack	*swap(t_stack *stack, int type)
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
	if (type == 0)
		ft_putstr_fd("sa\n", 1);
	else if (type == 1)
		ft_putstr_fd("sb\n", 1);
	else if (type == 2)
		ft_putstr_fd("ss\n", 1);
	return (next);
}

t_stack	*rotate(t_stack *stack, int type)
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
	if (type == 0)
		ft_putstr_fd("ra\n", 1);
	else if (type == 1)
		ft_putstr_fd("rb\n", 1);
	else if (type == 2)
		ft_putstr_fd("rr\n", 1);
	return (second);
}

t_stack	*reverse_rotate(t_stack *stack, int type)
{
	t_stack	*last;

	stack = get_first(stack);
	last = get_last(stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = stack;
	stack->prev = last;
	fix_index(last);
	if (type == 0)
		ft_putstr_fd("rra\n", 1);
	else if (type == 1)
		ft_putstr_fd("rrb\n", 1);
	else if (type == 2)
		ft_putstr_fd("rrr\n", 1);
	return (last);
}

t_stack	*push(t_stack *a, t_stack *b)
{
	t_stack	*a_second;

	a = get_first(a);
	a_second = a->next;
	if (!b)
	{
		b = a;
		a->prev = NULL;
		a->next = NULL;
		a_second->prev = NULL;
		fix_both(a_second, b);
		return (b);
	}
	else
	{
		b = get_first(b);
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

void	worst_case(t_stack *node)
{
	if (node->worst == 1)
	{
		r_or_rr(node, 0);
		r_or_rr(node->target, 1);
	}
	else
	{
		while (node->index > 0 && node->target->index > 0)
			r_or_rr_both(node);
		r_or_rr(node, 0);
		r_or_rr(node->target, 1);
	}
}
