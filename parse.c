/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balmaras <balmaras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:41:43 by balmaras          #+#    #+#             */
/*   Updated: 2025/11/28 15:13:35 by balmaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_syntax_correct(char *str_n)
{
	int	i;

	i = 0;
	while (str_n[i] == ' ' || (str_n[i] >= 9 && str_n[i] <= 13))
		i++;
	if (str_n[i] == '+' || str_n[i] == '-')
		i++;
	if (!str_n[i])
		return (0);
	while (str_n[i])
	{
		if (str_n[i] < '0' || str_n[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

void	free_split_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static int	fr_ret(t_stack **s)
{
	free_stack(s);
	return (0);
}

int	build_stack_from_args(t_stack **stack_a, char **args)
{
	long	num;
	t_stack	*new_node;
	int		i;

	i = 0;
	while (args[i])
	{
		if (!is_syntax_correct(args[i]))
			return (fr_ret(stack_a));
		num = ft_atol(args[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (fr_ret(stack_a));
		new_node = ft_stack_new((int)num);
		if (!new_node)
			return (fr_ret(stack_a));
		ft_stack_add_back(stack_a, new_node);
		i++;
	}
	return (1);
}
