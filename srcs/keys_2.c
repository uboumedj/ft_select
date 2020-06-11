/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2020/06/09 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		delete_key(t_terminal *term)
{
	t_lst *curr;

	curr = find_current_item(term->list);
	if (term->list == curr)
	{
		if (!(curr->next))
			escape_key(term);
		term->list = curr->next;
	}
	if (curr->next)
	{
		curr->next->is_current = 1;
		curr->next->prev = curr->prev;
	}
	if (curr->prev)
	{
		if (!(curr->next))
			curr->prev->is_current = 1;
		curr->prev->next = curr->next;
	}
	free_item(curr);
}

t_lst		*find_current_item(t_lst *list)
{
	t_lst *curr;

	curr = list;
	while (!curr->is_current)
		curr = curr->next;
	return (curr);
}

void		up_key(t_terminal *term)
{
	t_lst *curr;

	curr = find_current_item(term->list);
	curr->is_current = 0;
	if (curr->prev)
		curr->prev->is_current = 1;
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->is_current = 1;
	}
}

void		down_key(t_terminal *term)
{
	t_lst *curr;

	curr = find_current_item(term->list);
	curr->is_current = 0;
	if (curr->next)
		curr->next->is_current = 1;
	else
	{
		while (curr->prev)
			curr = curr->prev;
		curr->is_current = 1;
	}
}

void		left_key(t_terminal *term)
{
	int		len;
	t_lst	*curr;

	len = term->number_of_rows - 1;
	curr = find_current_item(term->list);
	curr->is_current = 0;
	if (!curr->prev)
	{
		while (curr->next)
			curr = curr->next;
		curr->is_current = 1;
	}
	else
	{
		while (len > 0)
		{
			if (!curr->prev)
				break ;
			curr = curr->prev;
			len--;
		}
		if (curr)
			curr->is_current = 1;
	}
}