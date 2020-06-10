/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2002/06/09 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

int		main(int argc, char **argv)
{
	t_terminal term;

	if (argc < 2)
		error_message(USAGE);
	initialise_terminal(&term);
	initialise_list(argv, &term);
	initialise_signals();
	initialise_display(&term);
	static_signal_handler(&term);
	tputs(tgetstr("cl", NULL), 1, putchar_err_output);
	tputs(tgetstr("ve", NULL), 1, putchar_err_output);
	free_list(term.list);
	return (0);
}
