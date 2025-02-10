/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:53:09 by dantoine          #+#    #+#             */
/*   Updated: 2025/01/27 18:41:23 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	exit_error(char *message)
{
	printf("%s\n", message);
	exit(1);
}

void	handle_fd_error(t_data *data)
{
	get_next_line(-1);
	cleanup_config(data, NULL, NULL, -1);
	exit_error("Error: Cannot open config file");
}
