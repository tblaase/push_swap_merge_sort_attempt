/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:50:30 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/06 16:37:20 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_big_sort_b(int argc, t_stack **stack_a, t_stack **stack_b)
/* this function will sort presorted data from stack_b to stack_a
** smallest number on top of stack
** stack_b = NULL when finished */
{
	t_stack	*temp_one;
	t_stack	*temp_two;
	int		i;

	temp_one = NULL;
	temp_two = NULL;
	i = 0;
	while (*stack_b != NULL)
	{
		if (i != 0 || *stack_a == NULL)
		{
			while ((*stack_b)->next != NULL // void ft_presort_pa(t_stack **stack_b)
				&& (*stack_b)->content > (*stack_b)->next->content)
			{
				(*stack_b)->swap = 0;
				ft_pa(stack_a, stack_b);
			}
			(*stack_b)->swap = 0;
			ft_pa(stack_a, stack_b);
			if (ft_one_stack_left_b(stack_b) == 1) // int ft_stack_check_b(t_stack **stack_b)
			{
				ft_set_swap(stack_b, 0);
				break ; //return (1) if (ft_stack_check == 1)
			}
			// return (0)
		}
		i = 0;
		if (*stack_b == NULL)
			break ;
		if ((*stack_b)->next == NULL)
		{
			while ((*stack_a)->content > (*stack_b)->content) // int ft_presort_last_b(t_stack **stack_a, t_stack **stack_b){t_stack *temp;}
			{
				(*stack_a)->swap = 1;
				ft_ra(stack_a, 1);
			}
			ft_pa(stack_a, stack_b);
			ft_lst_copy(stack_a, &temp_one);
			ft_rra(&temp_one, 0);
			if ((*stack_a)->content < (*stack_a)->next->content
				&& temp_one->content > (*stack_a)->content)
				(*stack_a)->swap = 1;
			else
			{
				(*stack_a)->swap = 0;
				while ((*stack_a)->swap == 0)
				{
					(*stack_a)->swap = 1;
					ft_ra(stack_a, 1);
				}
			}
			break ; // return (1); // if (ft_presort_last_b == 1)
		}
		ft_lst_copy(stack_b, &temp_one);
		ft_rrb(&temp_one, 0);
		ft_lst_copy(&temp_one, &temp_two);
		ft_rrb(&temp_two, 0);
		while (temp_one->content < temp_two->content)
		{
			if (i != 0) // so it will only check after first iteration
			{
				ft_lst_copy(stack_a, &temp_two); // int ft_presort_break_b(t_stack **stack_a, t_stack *temp_one/*, int i*/){if (i == 0)return (0);}
				ft_rra(&temp_two, 0);
				if (temp_two->content > temp_one->content && temp_two->swap != 0)
				{
					i++;
					break ; // return (1); // if (ft_presort_break_b == 1);
				}
			}
			i++;
			if ((*stack_a)->swap == 0 && temp_one->content < (*stack_a)->content) // int ft_presort_sort_b(t_stack **stack_a, t_stack **stack_b, t-stack *temp_one)
			{
				ft_rrb(stack_b, 1);
				ft_pa(stack_a, stack_b);
				(*stack_a)->swap = 1;
				ft_ra(stack_a, 1); //return (1);
			}
			else if ((*stack_a)->swap == 0)
			{
				(*stack_a)->swap = 1;
				ft_ra(stack_a, 1); //return (1);
			}//return (0);
			else // this will only happen if current part of stack_a got fully rotated and there is still part of stack_b left to be pushed // if (ft_presort_sort_b == 0)
			{
				if (*stack_b != NULL && (*stack_b)->next != NULL) // int ft_presort_rest_b(t_stack **stack_a, t_stack **stack_b, t_stack *temp_one, t_stack *temp_two)
				{
					ft_lst_copy(stack_b, &temp_one);
					ft_rrb(&temp_one, 0);
					ft_lst_copy(&temp_one, &temp_two);
					ft_rrb(&temp_two, 0);
					while (temp_one->content < temp_two->content)
					{
						ft_rrb(stack_b, 1);
						ft_pa(stack_a, stack_b);
						(*stack_a)->swap = 1;
						ft_ra(stack_a, 1);
						if ((*stack_b)->next == NULL)
							break ;
						ft_lst_copy(stack_b, &temp_one);
						ft_rrb(&temp_one, 0);
						ft_lst_copy(&temp_one, &temp_two);
						ft_rrb(&temp_two, 0);
					}
				}
				ft_rrb(stack_b, 1); // not protected, might cause problems
				ft_pa(stack_a, stack_b);
				(*stack_a)->swap = 1;
				ft_ra(stack_a, 1); // return (1)
				break ; //if (ft_presort_rest_b == 1);
			}
			if (*stack_b == NULL || (*stack_b)->next == NULL)
				break ;
				ft_lst_copy(stack_b, &temp_one);// use protected version
				ft_rrb(&temp_one, 0);
				ft_lst_copy(&temp_one, &temp_two);
				ft_rrb(&temp_two, 0);
		}
		if (*stack_b != NULL) //will prepare for the next iteration of the while loop // ft_presort_prepare_b(t_stack **stack_b, t_stack *temp_one, t_stack *temp_two)
		{
			ft_lst_copy(stack_b, &temp_one);
			ft_rrb(&temp_one, 0);
			if ((*stack_b)->next != NULL)
			{
				ft_lst_copy(&temp_one, &temp_two);
				ft_rrb(&temp_two, 0);
			}
		}
		if (*stack_b != NULL && ((*stack_b)->next == NULL || temp_one->content > temp_two->content)) // void ft_presort_cant_come_up_with_more_function_names(t_stack **stack_a, t_stack **stack_b, t_stack *temp_one, t_stack *temp_two)
		{
			while ((*stack_a)->content < temp_one->content
				&& (*stack_a)->swap == 0)
			{
				(*stack_a)->swap = 1;
				ft_ra(stack_a, 1);
			}
			ft_rrb(stack_b, 1);
			ft_pa(stack_a, stack_b);
			(*stack_a)->swap = 0;
		}
		while ((*stack_a)->swap == 0) // void ft_presort_prepare_two_b(t_stack **stack_a)
		{
			(*stack_a)->swap = 1;
			ft_ra(stack_a, 1);
		}
		if (ft_one_stack_left_b(stack_b) == 1)
		{
			ft_set_swap(stack_b, 0);
			break ;
		}
	}
	while ((*stack_a)->swap == 0) // void ft_presort_prepare_two_b(t_stack **stack_a)
	{
		(*stack_a)->swap = 1;
		ft_ra(stack_a, 1);
	}
	ft_free_all(&temp_one);
	ft_free_all(&temp_two);
	if (ft_if_sorted_a(argc, stack_a) == 1 && *stack_b == NULL)
		return ;
	ft_big_sort_a(argc, stack_a, stack_b);
}
