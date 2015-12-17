/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 08:28:21 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/17 08:28:23 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "errno.h"
#include <string.h>

int		main(int argc, char **argv)
{
	int				fd;
	char			*line;
	int				res;

	line = NULL;
	if (argc != 2)
	{
		ft_putstr("Wrong argument\n");
		exit(-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd != -1)
	{
		res = get_next_line(fd, &line);
		//ft_putnbr(res);
		res = get_next_line(fd, &line);
		//ft_putnbr(res);
	}
	else
		ft_putstr(strerror(errno));
	return (0);
}