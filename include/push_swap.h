/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:17:28 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/09 00:41:50 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				val;
	int				index;
	int				cost;
	int				above_mid;
	int				cheapest;
	int				worst;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char const c);
long	ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);

void	free_stack(t_stack *stack);
void	error_exit(void);
t_stack	*get_first(t_stack *node);
t_stack	*get_last(t_stack *stack);
t_stack	*fill_stack(char **tab);
void	free_tab(char **tab);
t_stack	*get_by_index(t_stack *stack, int index);
t_stack	*get_by_val(t_stack *stack, int val);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int		get_big_index(t_stack *stack);
int		get_small_index(t_stack *stack);
void	fix_index(t_stack *stack);
void	fix_both(t_stack *a, t_stack *b);
t_stack	*find_cheapest(t_stack *a);
void	get_targets(t_stack *a, t_stack *b);

void	check_above_mid(t_stack *a, t_stack *b, int i);
void	check_mid(t_stack *a);
void	cc_utils(t_stack *node, t_stack *target, int i);
void	calculate_costs(t_stack *a, t_stack *b);
t_stack	*get_biggest_smaller(t_stack *stack, int val);

void	argc2_error_handler(char **nums, char **argv, t_stack **stack);
void	int_error_handler(int **nums2, char **argv, int argc, t_stack **stack);
t_stack	*fill_stack_int(int *tab, int argc);

t_stack	*moves_to_b(t_stack *a, t_stack *b);
t_stack	*move1(t_stack *node, t_stack *b);
t_stack	*move2(t_stack *node, t_stack *b, int type);
void	worst_case(t_stack *node);

t_stack	*moves_to_a(t_stack *a, t_stack *b);

void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	turk_algo(t_stack *a);

t_stack	*swap(t_stack *stack, int type);
t_stack	*rotate(t_stack *stack, int type);
t_stack	*reverse_rotate(t_stack *stack, int type);
t_stack	*push(t_stack *a, t_stack *b);
void	r_or_rr(t_stack *node, int type);
void	r_or_rr_both(t_stack *node);

int		check_size(char *num);
int		check_duplicates_char(char **tab);
int		check_duplicates_int(int *tab, int argc);
int		check_invalid_char(char **tab, int type);
void	error_exit(void);

t_stack	*swap_b(t_stack *stack);
t_stack	*rotate_b(t_stack *stack);
t_stack	*reverse_rotate_b(t_stack *stack);
t_stack	*push_b(t_stack *a, t_stack *b);

int		step_checker(char **cmd, t_stack *a);
void	error_check(char **nums);
char	**read_stdin(void);
void	free_all(char **s1, char **s2, t_stack *stack);
void	free_and_exit(char **tab);
int		get_size(char **nums);
int		get_size_stack(t_stack *stack);

#endif