/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2020/06/10 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void	display_loop(t_terminal *term)
{
	display_list(term);
	while (1)
	{
		get_key_press(term);
		tputs(tgetstr("rc", NULL), 1, putchar_err_output);
		tputs(tgetstr("cd", NULL), 1, putchar_err_output);
		display_list(term);
	}
}

void	display_list(t_terminal *term)
{
	int		i;
	int		position;
	t_lst	*item;

	i = 0;
	item = term->list;
	position = -1;
	get_window_info(term);
	if (check_window_size(term) == SUCCESS)
	{
		while (item)
		{
			position = calc_display_position(term, position, i);
			display_item(item);
			item = item->next;
			i++;
		}
	}
}

int		calc_display_position(t_terminal *term, int position, int i)
{
	int j;
	int max_items_per_col;

	j = 0;
	max_items_per_col = term->number_of_rows - 1;
	if (i != 0 && (i % max_items_per_col) == 0)
	{
		position += (term->max_name_len + 2);
		tputs(tgetstr("rc", NULL), 1, putchar_err_output);
	}
	while (j++ <= position)
		tputs(tgetstr("nd", NULL), 1, putchar_err_output);
	return (position);
}

void	display_item(t_lst *item)
{
	if (item->is_current)
		tputs(tgetstr("us", NULL), 1, putchar_err_output);
	if (item->is_selected)
		tputs(tgetstr("so", NULL), 1, putchar_err_output);
	ft_putstr_fd("\033[32m", 0);
	ft_putstr_fd(item->name, 0);
	ft_putstr_fd("\033[00m", 0);
	ft_putchar_fd('\n', 0);
	if (item->is_current)
		tputs(tgetstr("ue", NULL), 1, putchar_err_output);
	if (item->is_selected)
		tputs(tgetstr("se", NULL), 1, putchar_err_output);
}
