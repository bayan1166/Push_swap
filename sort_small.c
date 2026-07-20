/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balmaras <balmaras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:21:34 by balmaras          #+#    #+#             */
/*   Updated: 2025/11/15 14:23:06 by balmaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *stack)
{
	int	min_val;
	int	min_index;
	int	i;

	if (!stack)
		return (-1);
	min_val = stack->value;
	min_index = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_index);
}

void	sort_three(t_stack **a)
{
	int	max;

	if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
		max = (*a)->value;
	else if ((*a)->next->value > (*a)->value
		&& (*a)->next->value > (*a)->next->next->value)
		max = (*a)->next->value;
	else
		max = (*a)->next->next->value;
	if ((*a)->value == max)
		ra(a);
	else if ((*a)->next->value == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static void	push_min_to_b(t_stack **a, t_stack **b)
{
	int	min_index;
	int	size;

	min_index = find_min_index(*a);
	size = ft_stack_size(*a);
	if (min_index <= size / 2)
		while (min_index-- > 0)
			ra(a);
	else
		while (min_index++ < size)
			rra(a);
	pb(a, b);
}

void	sort_four_five(t_stack **a, t_stack **b, int count)
{
	int	i;

	i = 0;
	while (i++ < count)
		push_min_to_b(a, b);
	sort_three(a);
	while (count-- > 0)
		pa(a, b);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stack_size(*a);
	if (size == 2 && (*a)->value > (*a)->next->value)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four_five(a, b, 1);
	else if (size == 5)
		sort_four_five(a, b, 2);
}
