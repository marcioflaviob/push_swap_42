/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:40:11 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/09 00:40:32 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
