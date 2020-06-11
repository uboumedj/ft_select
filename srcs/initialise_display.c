/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2020/06/10 17:03:53 by uboumedj         ###   ########.fr       */
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
	term->item_amount = 0;
	while (curr)
	{
		len = ft_strlen(curr->name);
		if (len > term->max_name_len)
			term->max_name_len = len;
		term->item_amount++;
		curr = curr->next;
	}
}

int			check_window_size(t_terminal *term)
{
	int item_columns;

	if (term->number_of_rows <= 1)
	{
		tputs(tgetstr("cl", NULL), 1, putchar_err_output);
		error_window_size();
		return (FAILURE);
	}
	item_columns = calc_item_columns_needed(term);
	if (((term->max_name_len + 2) * item_columns) > term->number_of_cols)
	{
		tputs(tgetstr("rc", NULL), 1, putchar_err_output);
		tputs(tgetstr("cd", NULL), 1, putchar_err_output);
		error_window_size();
		return (FAILURE);
	}
	return (SUCCESS);
}

int			calc_item_columns_needed(t_terminal *term)
{
	int result;

	result = (term->item_amount / (term->number_of_rows - 1));
	if (result == 0)
		result++;
	if (((term->number_of_rows - 1) * result) < term->item_amount)
		result++;
	return (result);
}
