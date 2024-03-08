/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:02:14 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/29 01:00:25 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_small_index(t_stack *stack)
{
	int	index;
	int	small;

	stack = get_first(stack);
	small = stack->val;
	index = stack->index;
	while (stack->next)
	{
		if (stack->next->val < small)
		{
			small = stack->next->val;
			index = stack->next->index;
		}
		stack = stack->next;
	}
	return (index);
}

t_stack	*get_smallest_bigger(t_stack *stack, int val)
{
	int		result;
	t_stack	*temp;

	temp = get_by_index(stack, get_big_index(stack));
	stack = get_first(stack);
	result = temp->val;
	while (stack->next)
	{
		if (stack->val > val && stack->val < result)
			result = stack->val;
		stack = stack->next;
	}
	if (stack->val > val && stack->val < result)
		result = stack->val;
	if (result < val)
		return (get_by_index(stack, get_small_index(stack)));
	return (get_by_val(stack, result));
}

void	check_mid(t_stack *a)
{
	int	size;

	a = get_first(a);
	size = stack_size(a);
	if (size % 2 == 0)
		size--;
	while (a->next)
	{
		if (a->index <= (size / 2))
			a->above_mid = 1;
		else
			a->above_mid = 0;
		a = a->next;
	}
	if (a->index <= (size / 2))
		a->above_mid = 1;
	else
		a->above_mid = 0;
}

t_stack	*moves_to_a(t_stack *a, t_stack *b)
{
	a = get_first(a);
	b = get_first(b);
	while (stack_size(b) > 1)
	{
		b->target = get_smallest_bigger(a, b->val);
		fix_both(a, b);
		check_mid(a);
		r_or_rr(b->target, 0);
		b = push(b, a);
		ft_putstr_fd("pa\n", 1);
	}
	b->target = get_smallest_bigger(a, b->val);
	fix_both(a, b);
	check_mid(a);
	r_or_rr(b->target, 0);
	b = push(b, a);
	ft_putstr_fd("pa\n", 1);
	fix_index(a);
	return (a);
}

void	check_above_mid(t_stack *a, t_stack *b, int i)
{
	int		size_a;
	int		size_b;
	t_stack	*node;
	t_stack	*target;

	size_a = stack_size(a);
	if (size_a % 2 == 0)
		size_a--;
	size_b = stack_size(b);
	if (size_b % 2 == 0)
		size_b--;
	node = get_by_index(a, i);
	target = node->target;
	if (i <= (size_a / 2))
		node->above_mid = 1;
	else
		node->above_mid = 0;
	if (target->index <= (size_b / 2))
		target->above_mid = 1;
	else
		target->above_mid = 0;
}
