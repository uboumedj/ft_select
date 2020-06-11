/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2020/06/09 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void	error_message(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

void	error_window_size(void)
{
	ft_putstr_fd("warning: console window size is too small for display\n", 2);
}

int		putchar_err_output(int c)
{
	return (write(2, &c, 1));
}
