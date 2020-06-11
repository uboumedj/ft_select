/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2020/06/10 18:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		get_key_press(t_terminal *term)
{
	char	buffer[5];

	ft_bzero(buffer, 5);
	if (read(0, buffer, 4) < 0)
	{
		free_list(term->list);
		error_message(RD_ERR);
	}
	if (*(unsigned int *)buffer == RETURN)
		return_key(term);
	if (*(unsigned int *)buffer == ESCAPE)
		escape_key(term);
	if (*(unsigned int *)buffer == SPACE)
		space_key(term);
	if (*(unsigned int *)buffer == BACKSPACE ||
			*(unsigned int *)buffer == DELETE)
		delete_key(term);
	if (*(unsigned int *)buffer == UP_ARROW)
		up_key(term);
	if (*(unsigned int *)buffer == DOWN_ARROW)
		down_key(term);
}

void		return_key(t_terminal *term)
{
	t_lst	*curr;

	clear_terminal(term);
	curr = term->list;
	while (curr)
	{
		if (curr->is_selected)
		{
			ft_putstr(curr->name);
			check_space_need(curr);
		}
		curr = curr->next;
	}
	free_list(term->list);
	ft_putchar('\n');
	exit(0);
}

void		check_space_need(t_lst *current_item)
{
	t_lst	*curr;

	curr = current_item;
	while (curr)
	{
		if (curr->is_selected)
		{
			ft_putchar(' ');
			break ;
		}
		curr = curr->next;
	}
}

void		escape_key(t_terminal *term)
{
	clear_terminal(term);
	free_list(term->list);
	exit(0);
}

void		space_key(t_terminal *term)
{
	t_lst *cur;

	cur = find_current_item(term->list);
	cur->is_selected = !cur->is_selected;
	down_key(term);
}
