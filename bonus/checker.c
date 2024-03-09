/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:22:01 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/09 13:36:56 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

	// char *cmd = "pb\npb\nra\nrra\npa\npa\nrra\nrra\n";
	// *commands = ft_split(cmd, '\n');

void	error_end(char **nums, t_stack **stack, char ***commands)
{
	error_check(nums);
	*stack = fill_stack(nums);
	*commands = read_stdin();
	if (!(*commands))
	{
		if (is_sorted(*stack))
		{
			ft_putstr_fd("OK\n", 1);
			free_tab(nums);
			free_stack(*stack);
			exit(1);
		}
		else
			(free(*stack), error_exit());
	}
}
	// char *argv[3];
	// int argc = 2;
	// char *bs = "bullshit";
	// char *nm = "4 5 6 1 2 a";

	// argv[0] = bs;
	// argv[1] = nm;
	// argv[2] = NULL;

// int main()
int	main(int argc, char **argv)
{
	char	**commands;
	char	**nums;
	t_stack	*stack;

	if (argc != 2)
		error_exit();
	if (argv[1][0] == 0)
		error_exit();
	nums = ft_split(argv[1], ' ');
	stack = NULL;
	commands = NULL;
	error_end(nums, &stack, &commands);
	if (step_checker(commands, stack))
	{
		if (get_size(nums) != get_size_stack(stack))
		{
			free_all(nums, commands, stack);
			ft_putstr_fd("KO\n", 1);
			exit(1);
		}
		ft_putstr_fd("OK\n", 1);
	}
	else
		ft_putstr_fd("KO\n", 1);
	free_all(nums, commands, stack);
}
