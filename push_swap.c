/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:17:31 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/26 15:17:31 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	first_check(t_stack *stack)
{
	int	size;

	size = stack_size(stack);
	if (size < 2)
		return (1);
	else if (size == 2)
	{
		sort_two(stack);
		return (1);
	}
	else if (size == 3)
	{
		if (!is_sorted(stack))
		{
			sort_three(stack);
			return (1);
		}
	}
	return (0);
}

void	last_organization(t_stack *stack)
{
	if (!is_sorted(stack))
	{
		stack = get_by_index(stack, get_small_index(stack));
		r_or_rr(stack, 0);
	}
}

// int main()
	// int argc = 2;
	// char **argv;
	// argv = malloc(150 * sizeof(char *));
	// argv[0] = malloc(5 * sizeof(char));
	// argv[1] = malloc(10 * sizeof(char));
	// argv[2] = malloc(5 * sizeof(char));
	// argv[3] = malloc(5 * sizeof(char));
	// argv[4] = malloc(5 * sizeof(char));
	// argv[5] = malloc(5 * sizeof(char));
	// argv[6] = malloc(5 * sizeof(char));
	// argv[7] = malloc(5 * sizeof(char));
	// argv[8] = malloc(5 * sizeof(char));
	// argv[9] = malloc(5 * sizeof(char));
	// argv[10] = malloc(5 * sizeof(char));
	// argv[11] = malloc(5 * sizeof(char));
	// argv[12] = malloc(5 * sizeof(char));
	// argv[13] = malloc(5 * sizeof(char));
	// argv[14] = malloc(5 * sizeof(char));
	// argv[15] = malloc(5 * sizeof(char));

	// argv[0] = "com";
	// argv[1] = "1 2 a";
	// argv[2] = "2";
	// argv[3] = "a";
	// argv[4] = "14";
	// argv[5] = "2";
	// argv[6] = "8";
	// argv[7] = "11";
	// argv[8] = "12";
	// argv[9] = "6";
	// argv[10] = "13";
	// argv[11] = "5";
	// argv[12] = "15";
	// argv[13] = "4";
	// argv[14] = "3";
	// argv[15] = "10";
int	main(int argc, char **argv)
{
	char	**nums;
	int		*nums2;
	t_stack	*stack;

	nums2 = NULL;
	nums = NULL;
	stack = NULL;
	if (argc < 2)
		exit (1);
	else if (argc == 2)
		argc2_error_handler(nums, argv, &stack);
	else if (argc > 2)
		int_error_handler(&nums2, argv, argc, &stack);
	if (is_sorted(stack))
		(free_stack(stack), exit(0));
	if (first_check(stack))
		(free_stack(stack), exit(0));
	turk_algo(stack);
	last_organization(stack);
	if (is_sorted(stack))
		free_stack(stack);
	return (0);
}
