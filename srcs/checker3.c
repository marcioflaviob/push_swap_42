/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:23:03 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/13 16:05:07 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	initialize(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	initialize(&i, &j);
	if (!s1)
	{
		s1 = malloc (1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = 0;
	free(s1);
	return (result);
}

void	free_all(char **s1, t_stack *stack)
{
	free_tab(s1);
	free_stack(stack);
}

void	get_sz(char **nums, int *nums2, int *size, int argc)
{
	int	i;

	i = 0;
	if (nums != NULL)
	{
		while (nums[i])
			i++;
		*size = i;
		free (nums);
		return ;
	}
	free (nums2);
	*size = (argc - 1);
}

int	get_size_stack(t_stack *stack)
{
	int	i;

	i = 0;
	stack = get_first(stack);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
