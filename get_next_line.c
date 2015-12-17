/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 08:18:01 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/17 08:18:03 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	int				res;
	char		*content;
	int				index_end_line;
	int				end_line;
	int				i;
	int				tmp_i;

	end_line = 0;
	i = 0;
	line = NULL;
	tmp_i = 0;
	content = (char*)malloc(sizeof(char) * (BUFF_SIZE));
	while ((res = read(fd, content, BUFF_SIZE)) && !end_line)
	{
		if (!end_line)
			index_end_line = 0;
		while (content[index_end_line])
		{
			ft_putchar(content[index_end_line]);
			if (content[index_end_line] == '\n') // || EOF ??
			{
				end_line = 1;
				break;
			}
			index_end_line++;
		}
		tmp_i = tmp_i + index_end_line;
	}
	//ft_putnbr(tmp_i);
	//while (i < tmp_i)
	//{
	//	ft_putchar(content[i]);
	//	i++;
	//}
	//ft_putstr(content);
	//ft_putnbr(i);
	return (1);
}