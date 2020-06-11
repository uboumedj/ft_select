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

/*
** Error messages
*/

# define USAGE "usage: ./ft_select [arg1] [arg2] [arg3] ...\n"
# define STD_INPUT_ERR "error: Standard input not associated to the terminal!\n"
# define ACCESS_ERR "error: Unable to access standard input\n"
# define TERM_ENV_ERR "error: Unable to access terminal type name in ENV\n"
# define NO_TERMDB_ERR "error: Unable to access terminal type database\n"
# define NO_TERM_ERR "error: Terminal type is not in the database!\n"
# define GET_ATTR_ERR "error: Unable to get standard input attributes\n"
# define SET_ATTR_ERR "error: Unable to set standard input attributes\n"
# define MEM_ERR "error: Unable to allocate memory!\n"
# define CLOSE_FD_ERR "error: Unable to close file descriptor\n"
# define RD_ERR "error: Unable to read from input\n"

# define FAILURE -1
# define SUCCESS 0

/*
** Key defines
*/

# define RETURN 10
# define ESCAPE 27
# define SPACE 32
# define BACKSPACE 127
# define UP_ARROW 4283163
# define DOWN_ARROW 4348699
# define DELETE 2117294875

/*
** Structures
*/

typedef struct			s_lst
{
	char				*name;
	int					name_len;
	char				is_selected;
	char				is_current;
	struct s_lst		*next;
	struct s_lst		*prev;
}						t_lst;

typedef struct			s_terminal
{
	t_lst				*list;
	int					fd;
	char				term_desc[4096];
	struct termios		termios_p;
	int					item_amount;
	int					max_name_len;
	int					number_of_cols;
	int					number_of_rows;
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
t_lst					*create_item(char **arguments, int index);
void					add_item_to_list(t_lst *item, t_terminal *term);

/*
** Initialise display
*/

void					initialise_display(t_terminal *term);
void					get_window_info(t_terminal *term);
void					get_list_info(t_terminal *term);
int						check_window_size(t_terminal *term);
int						calc_item_columns_needed(t_terminal *term);

/*
** Signals
*/

void					stop_signal(int signal_value);
void					quit_signal(int signal_value);
void					initialise_signals(void);

/*
** Display
*/

void					display_item(t_lst *item);
void					display_list(t_terminal *term);
int						calc_display_position(t_terminal *term, int pos, int i);
void					display_loop(t_terminal *term);

/*
** Key Handlers
*/

void					get_key_press(t_terminal *term);
void					check_space_need(t_lst *current_item);
void					return_key(t_terminal *term);
void					escape_key(t_terminal *term);
void					space_key(t_terminal *term);
t_lst					*find_current_item(t_lst *list);
void					delete_key(t_terminal *term);
void					up_key(t_terminal *term);
void					down_key(t_terminal *term);

/*
** Other functions
*/

int						putchar_err_output(int c);
t_terminal				*static_signal_handler(t_terminal *term);
void					error_message(char *message);
void					error_window_size(void);
void					free_list(t_lst *list);
void					free_item(t_lst *item);
void					clear_terminal(t_terminal *term);

#endif
