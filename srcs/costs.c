/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:13:14 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/08 13:39:04 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	cc_utils2(t_stack *node, t_stack *target)
{
	if (node->above_mid && target->above_mid)
	{
		if (target->cost > node->cost)
			node->cost = target->cost;
	}
	if (!node->above_mid && !target->above_mid)
	{
		if (target->cost > node->cost)
			node->cost = target->cost;
	}
}

void	cc_utils(t_stack *node, t_stack *target, int i)
{
	int		size_a;
	int		size_b;

	size_a = stack_size(node);
	size_b = stack_size(target);
	if (node->above_mid)
		node->cost = i;
	else
		node->cost = (size_a - i);
	if (target->above_mid)
		target->cost = target->index;
	else
		target->cost = (size_b - target->index);
	if (node->above_mid && !target->above_mid)
	{
		node->cost += target->cost;
		node->worst = 1;
	}
	if (!node->above_mid && target->above_mid)
	{
		node->cost += target->cost;
		node->worst = 1;
	}
	cc_utils2(node, target);
}

void	set_cheapest(t_stack *a)
{
	int		cost;
	int		index;

	cost = a->cost;
	a->cheapest = 0;
	index = a->index;
	a = a->next;
	while (a->next)
	{
		a->cheapest = 0;
		if (a->cost < cost)
		{
			cost = a->cost;
			index = a->index;
		}
		a = a->next;
	}
	a->cheapest = 0;
	if (a->cost < cost)
	{
		cost = a->cost;
		index = a->index;
	}
	a = get_by_index(a, index);
	a->cheapest = 1;
}

void	calculate_costs(t_stack *a, t_stack *b)
{
	int		i;
	int		size_a;
	t_stack	*temp;
	t_stack	*target;

	i = 0;
	a = get_first(a);
	b = get_first(b);
	size_a = stack_size(a);
	while (i < size_a)
	{
		temp = get_by_index(a, i);
		temp->worst = 0;
		target = temp->target;
		check_above_mid(a, b, i);
		cc_utils(temp, target, i);
		i++;
	}
	set_cheapest(a);
}

t_stack	*get_biggest_smaller(t_stack *stack, int val)
{
	int		result;
	t_stack	*temp;

	temp = get_by_index(stack, get_small_index(stack));
	stack = get_first(stack);
	result = temp->val;
	while (stack->next)
	{
		if (stack->val < val && stack->val > result)
			result = stack->val;
		stack = stack->next;
	}
	if (stack->val < val && stack->val > result)
		result = stack->val;
	if (result > val)
		return (get_by_index(stack, get_big_index(stack)));
	return (get_by_val(stack, result));
}
