/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:16:29 by dantoine          #+#    #+#             */
/*   Updated: 2024/03/18 15:15:51 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "get_next_line.h"

void	cleanlist(t_list **list)
{
	t_list	*last_node;
	t_list	*clean;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean = malloc(sizeof(t_list));
	if (buf == NULL || clean == NULL)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	k = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		++i;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buf[k++] = last_node->str_buf[i];
	buf[k] = '\0';
	clean->str_buf = buf;
	clean->next = NULL;
	unmalloc(list, clean, buf);
}

void	lstcat(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}

void	create_lst(t_list **list, int fd)
{
	int		bytesread;
	char	*buf;

	while (scanline(*list) != 1)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (!bytesread || bytesread < 0)
		{
			free(buf);
			return ;
		}
		buf[bytesread] = '\0';
		lstcat(list, buf);
	}
}

char	*get_line(t_list *list)
{
	int		len;
	char	*nxtline;

	len = charcount(list);
	nxtline = malloc(len + 1);
	if (nxtline == NULL)
		return (NULL);
	struct_strcpy(list, nxtline);
	return (nxtline);
}
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*nxtline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_lst(&list, fd);
	if (list == NULL)
		return (NULL);
	nxtline = get_line(list);
	cleanlist(&list);
	return (nxtline);
}
/*
#include <stdio.h>
#include <fcntl.h>

int     main(void)
{
        int fd;
        char *line;
        int lines;

        lines = 1;
        fd = open("notxt", O_RDONLY);

        while (line = get_next_line(fd))
        {
            printf("line %d: %s\n", lines++, line);    
        }
    free(line);
    return 0;
}*/
