/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balmaras <balmaras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:48:52 by balmaras          #+#    #+#             */
/*   Updated: 2025/11/28 14:50:57 by balmaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**parse_input_args(int argc, char **argv, int *is_split)
{
	*is_split = 0;
	if (argc == 2)
	{
		*is_split = 1;
		return (ft_split(argv[1], ' '));
	}
	return (argv + 1);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**args;
	int		is_split;

	stack_a = NULL;
	args = parse_input_args(argc, argv, &is_split);
	if (!args)
		return (NULL);
	if (!build_stack_from_args(&stack_a, args))
	{
		if (is_split)
			free_split_args(args);
		return (NULL);
	}
	if (is_split)
		free_split_args(args);
	if (check_duplicates(stack_a))
	{
		free_stack(&stack_a);
		return (NULL);
	}
	return (stack_a);
}
