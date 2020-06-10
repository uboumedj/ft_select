/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2002/06/10 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		initialise_display(t_terminal *term)
{
	get_window_info(term);
	get_list_info(term);
}

void		get_window_info(t_terminal *term)
{
	struct winsize	window_size;

	ioctl(0, TIOCGWINSZ, &window_size);
	term->number_of_rows = window_size.ws_row;
	term->number_of_cols = window_size.ws_col;
}

void		get_list_info(t_terminal *term)
{
	t_lst	*curr;
	int		len;

	curr = term->list;
	term->max_name_len = 0;
	term->number_of_elements = 0;
	while (curr)
	{
		len = ft_strlen(curr->name);
		if (len > term->max_name_len)
			term->max_name_len = len;
		term->number_of_elements++;
		curr = curr->next;
	}
}