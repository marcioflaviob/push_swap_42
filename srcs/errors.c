/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:37:57 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/08 23:39:36 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	check_invalid_char(char **tab, int type)
{
	int	i;
	int	j;

	i = 0;
	if (type)
		i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '-')
				j++;
			if (tab[i][j] == 0)
				return (1);
			else if (!ft_isdigit(tab[i][j]))
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicates_char(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicates_int(int *tab, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < (argc - 1))
	{
		j = i + 1;
		while (j < (argc - 1))
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_size(char *num)
{
	int	size;

	size = ft_strlen(num);
	if (num[0] == '-')
		size--;
	if (size > 10)
		return (1);
	return (0);
}
