/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:15:14 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/16 16:36:53 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
/* get the input from the user
** create linked list off of that
** sort that linked list by ascending oreder */
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (ft_input_error(argv) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	argc -= 1;
	stack_a = ft_fill_list(argc, argv);
	// ft_display_list(stack_a);
	// ft_display_list(stack_b);
	if (ft_if_sorted_a(argc, &stack_a) == 1)
		return (0);
	ft_sort(argc, &stack_a, &stack_b);
	// ft_display_list(stack_a);
	// ft_display_list(stack_b);
	// system("leaks push_swap");
	// fscanf(stdin, "c");
	return (0);
}
