/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_signals_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2020/06/10 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		resume_signal(int signal_value)
{
	t_terminal *term;

	(void)signal_value;
	term = NULL;
	term = static_signal_handler(term);
	term->termios_p.c_lflag &= ~ICANON;
	term->termios_p.c_lflag &= ~ECHO;
	term->termios_p.c_cc[VMIN] = 1;
	term->termios_p.c_cc[VTIME] = 0;
	tcsetattr(term->fd, TCSANOW, &term->termios_p);
	tputs(tgetstr("cl", NULL), 1, putchar_err_output);
	tputs(tgetstr("vi", NULL), 1, putchar_err_output);
	signal(SIGTSTP, stop_signal);
	display_list(term);
}