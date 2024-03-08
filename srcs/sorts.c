/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:02:23 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/08 23:42:13 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->val < stack->next->val)
		return ;
	swap(stack, 0);
}

void	sort_three(t_stack *stack)
{
	int	big_index;

	big_index = get_big_index(stack);
	if (big_index == 0)
		stack = rotate(stack, 0);
	else if (big_index == 1)
		stack = reverse_rotate(stack, 0);
	if (get_big_index(stack) == 2)
	{
		if (is_sorted(stack))
			return ;
		else
			stack = swap(stack, 0);
	}
	if (is_sorted(stack))
		return ;
}

void	turk_algo(t_stack *a)
{
	t_stack	*b;
	t_stack	*temp;

	b = NULL;
	temp = a->next;
	b = push(a, b);
	ft_putstr_fd("pb\n", 1);
	a = temp;
	if (stack_size(a) > 3)
	{
		a = push(a, b);
		ft_putstr_fd("pb\n", 1);
	}
	else if (stack_size(a) == 3)
	{
		sort_three(a);
		a = moves_to_a(a, b);
		return ;
	}
	a = moves_to_b(a, b);
	a = moves_to_a(a, b);
}
