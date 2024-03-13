/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:06:07 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/13 10:18:50 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_min_max_index(t_info *info, t_name name)
{
	t_stack	*temp;

	temp = info->stack[name];
	while (temp)
	{
		if (temp->value > info->max_stack[name][VALUE])
		{
			info->max_stack[name][VALUE] = temp->value;
			info->max_stack[name][INDEX] = temp->index;
		}
		if (temp->value < info->min_stack[name][VALUE])
		{
			info->min_stack[name][VALUE] = temp->value;
			info->min_stack[name][INDEX] = temp->index;
		}
		temp = temp->next;
	}
}

void	reset_info_index(t_info *info, t_name name)
{
	info->max_stack[name][VALUE] = MIN_INT;
	info->min_stack[name][VALUE] = MAX_INT;
}

void	initialise_info(t_info *info, t_stack **stack_a)
{
	info->stack[A] = *stack_a;
	info->stack[B] = NULL;
	info->size_stack[A] = stack_len(*stack_a);
	info->size_stack[B] = 0;
	info->max_stack[A][VALUE] = MIN_INT;
	info->max_stack[B][VALUE] = MIN_INT;
	info->min_stack[A][VALUE] = MAX_INT;
	info->min_stack[B][VALUE] = MAX_INT;
	info->movements = NULL;
}
