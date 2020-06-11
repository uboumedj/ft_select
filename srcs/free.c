/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2020/06/09 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void	free_list(t_lst *list)
{
	t_lst *next_item;

	while (list)
	{
		next_item = list->next;
		free_item(list);
		list = next_item;
	}
}

void	free_item(t_lst *item)
{
	if (item->name)
		ft_strdel(&(item->name));
	free(item);
}

void	clear_terminal(t_terminal *term)
{
	if (tcgetattr(term->fd, &term->termios_p) == -1)
		error_message(GET_ATTR_ERR);
	term->termios_p.c_lflag |= ICANON;
	term->termios_p.c_lflag |= ECHO;
	if (tcsetattr(term->fd, TCSANOW, &(term->termios_p)) == -1)
		error_message(SET_ATTR_ERR);
	tputs(tgetstr("cl", NULL), 1, putchar_err_output);
	tputs(tgetstr("ve", NULL), 1, putchar_err_output);
}
