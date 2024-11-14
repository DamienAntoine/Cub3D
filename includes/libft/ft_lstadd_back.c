/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:56:45 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/21 13:48:28 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	if (last == NULL)
	{
		*lst = new;
		return ;
	}
	else
		last->next = new;
}
/*
#include <stdio.h>
#include <assert.h>
void test_ft_lstadd_back()
{
	t_list *lst = ft_lstnew(ft_strdup("First"));
    assert(lst != NULL);

    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Second")));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Third")));
    ft_lstadd_back(&lst, NULL);

    assert(lst != NULL);
    assert(strcmp(lst->content, "First") == 0);
    assert(lst->next != NULL);
    assert(strcmp(lst->next->content, "Second") == 0);
    assert(lst->next->next != NULL);
    assert(strcmp(lst->next->next->content, "Third") == 0);
    assert(lst->next->next->next == NULL);

    ft_lstclear(&lst, free);
}

int main() {
    test_ft_lstadd_back();

    printf("***OK***\n");

    return 0;
}
*/