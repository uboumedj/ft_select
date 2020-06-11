/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_signals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2020/06/10 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		initialise_signals(void)
{
	signal(SIGINT, quit_signal);
	signal(SIGTSTP, stop_signal);
	signal(SIGCONT, resume_signal);
	signal(SIGQUIT, quit_signal);
	signal(SIGTERM, quit_signal);
	signal(SIGWINCH, winsize_change_signal);
}

void		stop_signal(int signal_value)
{
	t_terminal	*term;
	char		argp[2];

	(void)signal_value;
	term = NULL;
	term = static_signal_handler(term);
	argp[0] = term->termios_p.c_cc[VSUSP];
	argp[1] = 0;
	term->termios_p.c_lflag |= ICANON;
	term->termios_p.c_lflag |= ECHO;
	tcsetattr(term->fd, TCSANOW, &(term->termios_p));
	tputs(tgetstr("cl", NULL), 1, putchar_err_output);
	tputs(tgetstr("ve", NULL), 1, putchar_err_output);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, argp);
}

void		quit_signal(int signal_value)
{
	t_terminal *term;

	(void)signal_value;
	term = NULL;
	term = static_signal_handler(term);
	clear_terminal(term);
	free_list(term->list);
	if (close(term->fd) < 0)
		error_message(CLOSE_FD_ERR);
	exit(0);
}

void		winsize_change_signal(int signal_value)
{
	t_terminal	*term;

	(void)signal_value;
	term = NULL;
	term = static_signal_handler(term);
	clear_terminal(term);
	initialise_terminal(term);
	initialise_display(term);
	tputs(tgetstr("rc", NULL), 1, putchar_err_output);
	tputs(tgetstr("cd", NULL), 1, putchar_err_output);
	display_list(term);
}

t_terminal	*static_signal_handler(t_terminal *term)
{
	static t_terminal	*save = NULL;

	if (!save)
		save = term;
	return (save);
}
