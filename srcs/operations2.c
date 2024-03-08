/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:57:06 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/08 23:41:41 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	r_or_rr(t_stack *node, int type)
{
	while (node->index > 0)
	{
		if (node->above_mid)
			rotate(node, type);
		else
			reverse_rotate(node, type);
	}
	fix_index(node);
}

void	r_or_rr_both(t_stack *node)
{
	if (node->above_mid == 1)
	{
		rotate(node, 2);
		rotate(node->target, 3);
	}
	else
	{
		reverse_rotate(node, 2);
		reverse_rotate(node->target, 3);
	}
	fix_both(node, node->target);
}

//JUST TO SAVE LINES
t_stack	*move2(t_stack *node, t_stack *b, int type)
{
	t_stack	*subject;
	t_stack	*next;

	subject = node;
	if (type)
	{
		subject = node->target;
		r_or_rr(subject, 1);
	}
	else
		r_or_rr(subject, 0);
	next = node->next;
	push(node, b);
	ft_putstr_fd("pb\n", 1);
	return (next);
}

t_stack	*move1(t_stack *node, t_stack *b)
{
	t_stack	*next;

	if (node->index == 0 && node->cost == 0)
	{
		next = node->next;
		push(node, b);
		ft_putstr_fd("pb\n", 1);
		return (next);
	}
	else if (node->index == 0 && node->cost > 0)
	{
		return (move2(node, b, 1));
	}
	else if (node->index > 0 && node->target->cost == 0)
	{
		return (move2(node, b, 0));
	}
	else if (node->index > 0 && node->target->index > 0)
	{
		worst_case(node);
		next = node->next;
		(push(node, b), ft_putstr_fd("pb\n", 1));
		return (next);
	}
	return (NULL);
}

t_stack	*moves_to_b(t_stack *a, t_stack *b)
{
	a = get_first(a);
	b = get_first(b);
	while (stack_size(a) > 3)
	{
		a = get_first(a);
		b = get_first(b);
		get_targets(a, b);
		calculate_costs(a, b);
		a = get_first(move1(find_cheapest(a), b));
	}
	sort_three(a);
	fix_index(a);
	return (a);
}
