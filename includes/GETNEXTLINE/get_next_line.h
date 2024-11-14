/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:22:35 by dantoine          #+#    #+#             */
/*   Updated: 2024/03/13 14:22:36 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_tab
{
	char			*str_buf;
	struct s_tab	*next;
}		t_tab;

int		scanline(t_tab *tab);
t_tab	*ft_tablast(t_tab *lst);
char	*get_line(t_tab *tab);
void	struct_strcpy(t_tab *tab, char *str);
int		charcount(t_tab *tab);
void	cleanlist(t_tab **tab);
char	*get_next_line(int fd);
void	unmalloc(t_tab **tab, t_tab *clean, char *buf);
void	create_lst(t_tab **tab, int fd);

#endif
