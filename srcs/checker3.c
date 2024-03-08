/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:23:03 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/09 00:19:33 by mbrandao         ###   ########.fr       */
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

void	free_all(char **s1, char **s2, t_stack *stack)
{
	free_tab(s1);
	free_tab(s2);
	free_stack(stack);
}

int	get_size(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
		i++;
	return (i);
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
