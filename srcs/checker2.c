/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:20:23 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/08 23:24:07 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	step_checker3(char **cmd, t_stack ***a, t_stack ***b, int i)
{
	if (cmd[i][0] == 's' && cmd[i][1] == 'a')
		**a = swap_b(**a);
	else if (cmd[i][0] == 's' && cmd[i][1] == 'b')
		**b = swap_b(**b);
	else if (cmd[i][0] == 's' && cmd[i][1] == 's')
	{
		**a = swap_b(**a);
		**b = swap_b(**b);
	}
	else if (cmd[i][0] == 'p' && cmd[i][1] == 'b')
	{
		if (!(**b))
		{
			**a = (**a)->next;
			**b = push_b(**a, **b);
		}
		else
			**a = push_b(**a, **b);
	}
}

void	step_checker2(char **cmd, t_stack **a, t_stack **b, int i)
{
	if (cmd[i][0] == 'p' && cmd[i][1] == 'a')
		*b = push_b(*b, *a);
	else if (cmd[i][0] == 'r' && cmd[i][1] == 'a')
		*a = rotate_b(*a);
	else if (cmd[i][0] == 'r' && cmd[i][1] == 'b')
		*b = rotate_b(*b);
	else if (cmd[i][0] == 'r' && cmd[i][1] == 'r' && cmd[i][2] == 0)
	{
		*a = rotate_b(*a);
		*b = rotate_b(*b);
	}
	else if (cmd[i][0] == 'r' && cmd[i][1] == 'r' && cmd[i][2] == 'a')
		*a = reverse_rotate_b(*a);
	else if (cmd[i][0] == 'r' && cmd[i][1] == 'r' && cmd[i][2] == 'b')
		*b = reverse_rotate_b(*b);
	else if (cmd[i][0] == 'r' && cmd[i][1] == 'r' && cmd[i][2] == 'r')
	{
		*a = reverse_rotate_b(*a);
		*b = reverse_rotate_b(*b);
	}
	else
		step_checker3(cmd, &a, &b, i);
}

int	step_checker(char **cmd, t_stack *a)
{
	int		i;
	t_stack	*b;

	i = 0;
	b = NULL;
	while (cmd[i])
	{
		a = get_first(a);
		if (b)
			b = get_first(b);
		step_checker2(cmd, &a, &b, i);
		i++;
	}
	if (is_sorted(a))
		return (1);
	return (0);
}

char	**read_stdin(void)
{
	char	*buff;
	char	*str;
	char	**result;

	buff = (char *) malloc (2 * sizeof(char));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	buff[1] = 0;
	str = NULL;
	result = NULL;
	while (read(0, buff, 1) > 0)
	{
		str = ft_strjoin(str, buff);
		buff[1] = 0;
	}
	if (str)
	{
		result = ft_split(str, '\n');
		free(str);
	}
	free (buff);
	return (result);
}

void	error_check(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		if (check_invalid_char(nums, 0))
			free_and_exit(nums);
		if (check_duplicates_char(nums))
			free_and_exit(nums);
		if (check_size(nums[i]))
			free_and_exit(nums);
		if (ft_atoi(nums[i]) > INT_MAX || ft_atoi(nums[i]) < INT_MIN)
		{
			free_tab(nums);
			error_exit();
		}
		i++;
	}
}
