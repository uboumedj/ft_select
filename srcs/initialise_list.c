/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2002/06/10 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void	initialise_list(char **argv, t_terminal *term)
{
	int		i;
	t_lst	*new_item;

	i = 1;
	term->list = NULL;
	while (argv[i])
	{
		new_item = create_item(argv[i]);
		if (!new_item)
			error_message(MEM_ERR);
		add_item_to_list(new_item, term);
		i++;
	}
}

t_lst	*create_item(char *name)
{
	t_lst	*new;

	if (!(new = malloc(sizeof(t_lst))))
		return (NULL);
	new->name = ft_strdup(name);
	if (!(new->name))
		return (NULL);
	new->name_len = ft_strlen(name);
	new->next = NULL;
	new->prev = NULL;
	new->is_selected = 0;
	return (new);
}

void	add_item_to_list(t_lst *item, t_terminal *term)
{
	t_lst	*curr_list;

	if (!(term->list))
		term->list = item;
	else
	{
		curr_list = term->list;
		while (curr_list->next)
			curr_list = curr_list->next;
		curr_list->next = item;
		item->prev = curr_list;
	}
}
