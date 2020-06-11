/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2020/06/09 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		right_key(t_terminal *term)
{
	int		len;
	t_lst	*curr;

	len = term->number_of_rows - 1;
	curr = find_current_item(term->list);
	curr->is_current = 0;
	if (!curr->next)
	{
		while (curr->prev)
			curr = curr->prev;
		curr->is_current = 1;
	}
	else
	{
		while (len > 0)
		{
			if (!curr->next)
				break ;
			curr = curr->next;
			len--;
		}
		if (curr)
			curr->is_current = 1;
	}
}