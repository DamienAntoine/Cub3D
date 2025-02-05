/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:09:45 by dantoine          #+#    #+#             */
/*   Updated: 2024/03/13 14:12:03 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstcleartab(t_tab **lst)
{
	t_tab	*current;
	t_tab	*next;

	if (lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current->str_buf);
		free(current);
		current = next;
	}
	*lst = NULL;
}
