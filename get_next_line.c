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

char	*add_in_tmp(char *tmp, char *content, int index_end_line)
{
	char 	*tmp_2;
	int 	i;
	int 	new_len;

	i = 0;
	new_len = (ft_strlen(tmp) + ft_strlen(content));
	tmp_2 = (char*)malloc(sizeof(char) * ft_strlen(tmp));
	while (tmp[i])
	{
		tmp_2[i] = tmp[i];
		i++;
	}
	tmp = (char*)malloc(sizeof(char) * (new_len));
	tmp = ft_strcat(tmp, tmp_2);
	tmp = ft_strncat(tmp, content, index_end_line);
	free(tmp_2);
	return (tmp);
}

int		get_next_line(int const fd, char **line)
{
	int				res;
	char			*content;
	static char		*tmp;
	int				index_end_line;
	int				end_line;
	int				tmp_len;
	static int 		line_nbr;
	int 			line_tmp;

	end_line = 0;
	line_tmp = 0;
	line = NULL;
	if (!tmp)
		tmp = (char*)malloc(sizeof(char));
	tmp_len = ft_strlen(tmp);
	content = (char*)malloc(sizeof(char) * (BUFF_SIZE));
	while ((res = read(fd, content, BUFF_SIZE)) && !end_line)
	{
		index_end_line = 0;
		while (content[index_end_line])
		{
			if (content[index_end_line] == '\n') // || EOF ??
			{
				line_tmp++;
				ft_putnbr(line_tmp);
				if (line_tmp == (line_nbr + 1))
				{
					end_line = 1;
					break;
				}
			}
			index_end_line++;
		}
		if (line_tmp == (line_nbr + 1))
			tmp = add_in_tmp(tmp, content, index_end_line);
	}
	/*line = malloc(sizeof(char*) * ft_strlen(tmp));
	line = ft_strcpy(*line, tmp); */
	//ft_putstr(tmp);
	if (end_line)
	{
		line_nbr++;
		return (1);
	}
	else if (!end_line)
		return (0);
	else
		return (-1);
}