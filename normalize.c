/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balmaras <balmaras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:11:46 by balmaras          #+#    #+#             */
/*   Updated: 2025/11/28 14:23:16 by balmaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

void	quick_sort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

int	*stack_to_array(t_stack *stack, int size)
{
	int		*arr;
	int		i;
	t_stack	*current;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	current = stack;
	while (current)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	return (arr);
}

void	assign_indices(t_stack **stack_a, int *sorted_array, int size)
{
	t_stack	*current;
	int		i;

	current = *stack_a;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == sorted_array[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	normalize_stack(t_stack **stack_a)
{
	int		*sorted_array;
	int		size;

	size = ft_stack_size(*stack_a);
	sorted_array = stack_to_array(*stack_a, size);
	if (!sorted_array)
	{
		free_stack(stack_a);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	quick_sort(sorted_array, 0, size - 1);
	assign_indices(stack_a, sorted_array, size);
	free(sorted_array);
}
