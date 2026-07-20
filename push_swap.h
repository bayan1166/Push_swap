/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balmaras <balmaras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:11:24 by balmaras          #+#    #+#             */
/*   Updated: 2025/11/28 14:51:08 by balmaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);
void	sort_four_five(t_stack **a, t_stack **b, int count);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
t_stack	*init_stack(int argc, char **argv);
void	sort_small(t_stack **a, t_stack **b);

void	normalize_stack(t_stack **stack_a);
int		*stack_to_array(t_stack *stack, int size);
void	quick_sort(int *arr, int low, int high);
void	assign_indices(t_stack **stack_a, int *sorted_array, int size);

t_stack	*ft_stack_new(int value);
void	ft_stack_add_back(t_stack **stack, t_stack *new_node);
int		ft_stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
long	ft_atol(const char *str);
void	ft_putstr_fd(char *s, int fd);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

char	**ft_split(char const *s, char c);

int		build_stack_from_args(t_stack **stack_a, char **args);
void	free_split_args(char **args);
int		check_duplicates(t_stack *stack);
int		is_syntax_correct(char *str_n);

#endif
