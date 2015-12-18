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
	char	*tmp_2;
	int		i;
	int		new_len;

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

char	*get_line(int line_nbr, char *tmp, int i, int i_2)
{
	int		line;
	char	*tmp_line;

	line = 0;
	while (tmp[i])
	{
		if (line == line_nbr)
			break ;
		if (tmp[i] == '\n')
			line++;
		i++;
	}
	if (!(tmp_line = (char*)malloc(sizeof(char) * ft_strlen(tmp))))
		return (NULL);
	while (tmp[i] != '\n' && tmp[i] != '\0')
	{
		tmp_line[i_2] = tmp[i];
		i++;
		i_2++;
	}
	tmp_line[i_2] = '\0';
	if (!i_2 && tmp[i + 1])
		return (NULL);
	return (tmp_line);
}

int		get_state(char *line)
{
	if (!line)
	{
		line = "\0";
		return (1);
	}
	if (ft_strlen(line))
		return (1);
	else if (!ft_strlen(line))
		return (0);
	else
		return (-1);
}

int		get_next_line(int const fd, char **line)
{
	int				res;
	char			*content;
	static char		*tmp;
	static int		line_nbr;
	char			*line_tmp;

	if (!line_nbr)
		line_nbr = 0;
	if (!tmp)
		tmp = (char*)malloc(sizeof(char));
	content = (char*)malloc(sizeof(char) * (BUFF_SIZE));
	while ((res = read(fd, content, BUFF_SIZE)))
		tmp = add_in_tmp(tmp, content, res);
	line_tmp = get_line(line_nbr, tmp, 0, 0);
	*line = line_tmp;
	line_nbr++;
	return (get_state(line_tmp));
}
