/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:51:49 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/08 23:42:06 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void	print_stack(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	i;

// 	i = 0;
// 	while (stack_a->next || stack_b->next)
// 	{
// 		if (stack_a && stack_a->next)
// 			ft_printf("%d  |", stack_a->val);
// 		if (stack_b && stack_b->next)
// 			ft_printf("  %d\n", stack_b->val);
// 		else if (!stack_b)
// 			ft_printf("\n");
// 		stack_a = stack_a->next;
// 		stack_b = stack_b->next;
// 	}
// 	if (stack_a && stack_a->next)
// 		ft_printf("%d  |", stack_a->val);
// 	if (stack_b && stack_b->next)
// 		ft_printf("  %d\n", stack_b->val);
// 	else if (!stack_b)
// 		ft_printf("\n");
// }

void	free_stack(t_stack *stack)
{
	t_stack	*next;
	int		i;

	i = 0;
	stack = get_first(stack);
	next = stack->next;
	while (next)
	{
		free(stack);
		stack = next;
		next = stack->next;
	}
	free(stack);
}

t_stack	*fill_stack(char **tab)
{
	int		i;
	t_stack	*stack;
	t_stack	*previous;

	i = 0;
	stack = (t_stack *) malloc(sizeof(t_stack));
	stack->prev = NULL;
	previous = stack;
	while (tab[i])
	{
		stack->index = i;
		stack->worst = 0;
		stack->val = ft_atoi(tab[i++]);
		if (tab[i])
		{
			stack->next = malloc(sizeof(t_stack));
			stack = stack->next;
			stack->prev = previous;
			previous = stack;
		}
	}
	stack->next = NULL;
	return (get_first(stack));
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_stack	*find_cheapest(t_stack *a)
{
	t_stack	*temp;

	a = get_first(a);
	while (a->next)
	{
		if (a->cheapest)
		{
			temp = a;
			return (temp);
		}
		a = a->next;
	}
	if (a->cheapest)
	{
		temp = a;
		return (temp);
	}
	return (NULL);
}
