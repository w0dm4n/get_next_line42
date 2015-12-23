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

char	*add_in(char *buffer, char *toadd, int oct, int i)
{
	int		new_len;
	char	*tmp;

	new_len = (ft_strlen(buffer) + ft_strlen(toadd));
	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(buffer) + 1))))
		return (NULL);
	while (buffer[i])
	{
		tmp[i] = buffer[i];
		i++;
	}
	tmp[i] = '\0';
	i = 0;
	if (!(buffer = (char*)malloc(sizeof(char) * (new_len + 1))))
		return (NULL);
	buffer = ft_strcat(buffer, tmp);
	buffer = ft_strncat(buffer, toadd, oct);
	free(tmp);
	return (buffer);
}

t_gnl	*alloc_list(t_gnl *list)
{
	if (!(list = (t_gnl *)malloc(sizeof(t_gnl*))))
		return (NULL);
	else if (!(list->buffer = (char *)malloc(sizeof(char))))
		return (NULL);
	ft_bzero(list->buffer, 1);
	list->already_read = 0;
	list->line = 0;
	return (list);
}

t_gnl	*read_file(int fd, t_gnl *list, int res)
{
	char *content;

	if (!(content = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (NULL);
	while ((res = read(fd, content, BUFF_SIZE)))
		if (!(list->buffer = add_in(list->buffer, content, res, 0)))
			return (NULL);
	free(content);
	return (list);
}

char	*get_line(char *buffer, int line, int i, int i_2)
{
	int		line_pos;
	char	*line_tmp;

	line_pos = 0;
	while (buffer[i])
	{
		if (line_pos == line)
			break ;
		if (buffer[i] == '\n')
			line_pos++;
		i++;
	}
	if (!(line_tmp = (char*)malloc(sizeof(char) * (ft_strlen(buffer) + 1))))
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		line_tmp[i_2++] = buffer[i++];
	line_tmp[i_2] = '\0';
	if (!i_2 && buffer[i + 1])
		return (NULL);
	return (line_tmp);
}

int		get_next_line(int const fd, char **line)
{
	static t_gnl	*list;
	char			*line_tmp;
	if (!list)
		if (!(list = alloc_list(list)))
			return (-1);
	if (!list->already_read)
	{
		if (!(list = read_file(fd, list, 0)))
			return (-1);
		list->already_read++;
	}
	line_tmp = get_line(list->buffer, list->line, 0, 0);
	*line = line_tmp;
	list->line++;
	if (!line_tmp)
	{
		line_tmp = "\0";
		return (1);
}
	return ((line_tmp[0] != '\0') ? 1 : 0);
}
