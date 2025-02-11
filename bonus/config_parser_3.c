/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:37:47 by sanhwang          #+#    #+#             */
/*   Updated: 2025/02/11 22:49:38 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	cleanup_config(t_data *data, char *line, char **split, int fd)
{
	if (line)
		free(line);
	if (split)
		free_split(split);
	if (fd > 0)
	{
		get_next_line(-1);
		close(fd);
	}
	if (data)
		free_resources(data);
}
