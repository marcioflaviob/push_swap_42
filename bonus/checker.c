/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:22:01 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/13 23:15:38 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_cmd(char **commands)
{
	if (commands)
		free(commands);
}

	// char *cmd = "";
	// *commands = ft_split(cmd, '\n');
void	ee(char **nums, int *nums2, t_stack **stack, char ***commands)
{
	*commands = read_stdin();
	if (!(*commands) || !(**commands))
	{
		if (is_sorted(*stack))
		{
			ft_putstr_fd("OK\n", 1);
			if (nums2 == NULL)
				free_tab(nums);
			else
				free (nums2);
			free_stack(*stack);
			(free_cmd(*commands), exit(1));
		}
		else
		{
			if (nums2 == NULL)
				free_tab(nums);
			else
				free (nums2);
			(free_cmd(*commands), free(*stack), error_exit());
		}
	}
}

void	argc2_error_checker(char ***nums, char **argv, t_stack **stack)
{
	int	i;

	i = 0;
	if (argv[1][0] == 0)
		error_exit();
	*nums = ft_split(argv[1], ' ');
	if (check_invalid_char(*nums, 0))
		free_and_exit(*nums);
	if (check_duplicates_char(*nums))
		free_and_exit(*nums);
	while ((*nums)[i])
	{
		if (check_size((*nums)[i]))
			free_and_exit(*nums);
		if (ft_atoi((*nums)[i]) > INT_MAX || ft_atoi((*nums)[i]) < INT_MIN)
			free_and_exit(*nums);
		i++;
	}
	*stack = fill_stack(*nums);
}

void	int_error_checker(int **nums2, char **argv, int argc, t_stack **stack)
{
	int	i;

	i = 0;
	if (check_invalid_char(argv, 1))
		error_exit();
	*nums2 = (int *) malloc ((argc - 1) * sizeof(int));
	while (i < (argc - 1))
	{
		if (ft_atoi(argv[i + 1]) > INT_MAX || ft_atoi(argv[i + 1]) < INT_MIN)
			(free (*nums2), exit(1));
		(*nums2)[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (check_duplicates_int(*nums2, argc))
	{
		free(*nums2);
		error_exit();
	}
	*stack = fill_stack_int(*nums2, argc);
}

	// char *argv[3];
	// int argc = 2;
	// char *bs = "random";
	// char *nm = "1";

	// argv[0] = bs;
	// argv[1] = nm;
	// argv[2] = NULL;

// int main()
int	main(int argc, char **argv)
{
	char	**commands;
	int		nums_size;
	char	**nums;
	int		*nums2;
	t_stack	*stack;

	nums2 = NULL;
	nums = NULL;
	stack = NULL;
	commands = NULL;
	if (argc < 2)
		exit (1);
	else if (argc == 2)
		argc2_error_checker(&nums, argv, &stack);
	else if (argc > 2)
		int_error_checker(&nums2, argv, argc, &stack);
	(ee(nums, nums2, &stack, &commands), get_sz(nums, nums2, &nums_size, argc));
	if (step_checker(commands, stack))
	{
		if (nums_size != get_size_stack(stack))
			(free_all(commands, stack), ft_putstr_fd("KO\n", 1), exit(1));
		(ft_putstr_fd("OK\n", 1), free_all(commands, stack));
	}
	else
		(ft_putstr_fd("KO\n", 1), free_all(commands, stack));
}
