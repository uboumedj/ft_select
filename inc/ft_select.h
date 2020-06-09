/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2020/06/09 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/inc/libft.h"
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>
# include <term.h>

# define USAGE "usage: ./ft_select [arg1] [arg2] [arg3] ...\n"
# define STD_INPUT_ERR "error: Standard input not associated to the terminal!\n"
# define ACCESS_ERR "error: Unable to access standard input\n"
# define TERM_ENV_ERR "error: Unable to access terminal type name in ENV\n"
# define NO_TERMDB_ERR "error: Unable to access terminal type database\n"
# define NO_TERM_ERR "error: Terminal type is not in the database!\n"
# define GET_ATTR_ERR "error: Unable to get standard input attributes\n"
# define SET_ATTR_ERR "error: Unable to set standard input attributes\n"
# define MEM_ERR "error: Unable to allocate memory!\n"

typedef struct			s_lst
{
	char				*name;
	int					name_len;
	char				is_selected;
	struct s_lst		*next;
	struct s_lst		*prev;
}						t_lst;

typedef struct			s_terminal
{
	t_lst				*list;
	int					fd;
	char				term_desc[4096];
	struct termios		termios_p;
}						t_terminal;

/*
** Initialise terminal
*/

void					get_terminal_description(t_terminal *term);
void					check_stdin_access(t_terminal *term);
void					get_stdin_attributes(t_terminal *term);
void					set_stdin_attributes(t_terminal *term);
void					initialise_terminal(t_terminal *term);

/*
** Initialise list
*/

void					initialise_list(char **argv, t_terminal *term);
t_lst					*create_item(char *name);
void					add_item_to_list(t_lst *item, t_terminal *term);

/*
** Other functions
*/

int						putchar_err_output(int c);
void					error_message(char *message);
void					free_list(t_lst *list);

#endif
