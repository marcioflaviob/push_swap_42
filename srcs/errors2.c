/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:40:11 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/14 12:17:42 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*fill_stack_int(int *tab, int argc)
{
	int		i;
	t_stack	*stack;
	t_stack	*previous;

	i = 0;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->prev = NULL;
	previous = stack;
	while (i < (argc - 1))
	{
		stack->index = i;
		stack->worst = 0;
		stack->val = tab[i++];
		if (i < (argc - 1))
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

void	free_and_exit(char **tab)
{
	free_tab(tab);
	error_exit();
}

void	argc2_error_handler(char **nums, char **argv, t_stack **stack)
{
	int	i;

	i = 0;
	if (argv[1][0] == 0)
		error_exit();
	nums = ft_split(argv[1], ' ');
	if (check_invalid_char(nums, 0))
		free_and_exit(nums);
	if (check_duplicates_char(nums))
		free_and_exit(nums);
	while (nums[i])
	{
		if (check_size(nums[i]))
			free_and_exit(nums);
		if (ft_atoi(nums[i]) > INT_MAX || ft_atoi(nums[i]) < INT_MIN)
			free_and_exit(nums);
		i++;
	}
	*stack = fill_stack(nums);
	free_tab(nums);
}

void	int_error_handler(int **nums2, char **argv, int argc, t_stack **stack)
{
	int	i;

	i = 0;
	if (check_invalid_char(argv, 1))
		error_exit();
	*nums2 = (int *) malloc ((argc - 1) * sizeof(int));
	while (i < (argc - 1))
	{
		if (ft_atoi(argv[i + 1]) > INT_MAX || ft_atoi(argv[i + 1]) < INT_MIN)
			(free (*nums2), error_exit());
		(*nums2)[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (check_duplicates_int(*nums2, argc))
	{
		free(*nums2);
		error_exit();
	}
	*stack = fill_stack_int(*nums2, argc);
	free(*nums2);
}
