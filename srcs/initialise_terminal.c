/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_terminal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2020/06/10 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void	initialise_terminal(t_terminal *term)
{
	get_terminal_description(term);
	check_stdin_access(term);
	get_stdin_attributes(term);
	set_stdin_attributes(term);
}

void	get_terminal_description(t_terminal *term)
{
	char	*term_env_name;
	int		value;

	term_env_name = getenv("TERM");
	if (!term_env_name)
		error_message(TERM_ENV_ERR);
	value = tgetent(term->term_desc, term_env_name);
	if (value < 0)
		error_message(NO_TERMDB_ERR);
	else if (value == 0)
		error_message(NO_TERM_ERR);
}

void	check_stdin_access(t_terminal *term)
{
	int		fd;

	if (!isatty(0))
		error_message(STD_INPUT_ERR);
	fd = open(ttyname(0), O_RDWR);
	if (fd == -1)
		error_message(ACCESS_ERR);
	else
		term->fd = fd;
}

void	get_stdin_attributes(t_terminal *term)
{
	int value;

	value = tcgetattr(term->fd, &(term->termios_p));
	if (value == -1)
		error_message(GET_ATTR_ERR);
}

void	set_stdin_attributes(t_terminal *term)
{
	term->termios_p.c_lflag &= ~ICANON;
	term->termios_p.c_lflag &= ~ECHO;
	term->termios_p.c_cc[VMIN] = 1;
	term->termios_p.c_cc[VTIME] = 0;
	if (tcsetattr(term->fd, TCSANOW, &(term->termios_p)) == -1)
		error_message(SET_ATTR_ERR);
	tputs(tgetstr("vi", NULL), 1, putchar_err_output);
	tputs(tgetstr("cl", NULL), 1, putchar_err_output);
	tputs(tgetstr("sc", NULL), 1, putchar_err_output);
}
