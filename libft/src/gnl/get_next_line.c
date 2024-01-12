/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:41:30 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/06 18:57:33 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_buf(int fd, char *buf);
static char	*ft_strjoin(char *s1, char *s2);
static char	*split_line(char *buf);
static char	*update_buf(char *buf);

char	*get_next_line(int fd)
{
	static char	*buf[4096];
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 4096)
		return (NULL);
	buf[fd] = get_buf(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = split_line(buf[fd]);
	buf[fd] = update_buf(buf[fd]);
	return (line);
}

static char	*get_buf(int fd, char *buf)
{
	int		n_read;
	char	*new_line;

	n_read = 1;
	new_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_line)
		return (NULL);
	while (n_read > 0)
	{
		n_read = read(fd, new_line, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(new_line);
			return (NULL);
		}
		new_line[n_read] = '\0';
		buf = ft_strjoin(buf, new_line);
		if (next_char(buf, '\n'))
			break ;
	}
	free(new_line);
	return (buf);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*fs;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		*s1 = 0;
	}
	if (!s2)
		return (s1);
	fs = (char *)malloc((ft_count(s1) + ft_count(s2) + 1) * sizeof(char));
	if (!fs)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[j])
		fs[i++] = s1[j++];
	j = 0;
	while (s2[j])
		fs[i++] = s2[j++];
	fs[i] = '\0';
	free(s1);
	return (fs);
}

static char	*split_line(char *buf)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[j] && buf[j] != '\n')
		line[i++] = buf[j++];
	if (buf[j] == '\n')
		line[i++] = buf[j++];
	line[i] = '\0';
	return (line);
}

static char	*update_buf(char *buf)
{
	char	*new_buf;
	int		i;
	int		j;

	i = 0;
	j = next_char(buf, '\n');
	if (j < 1)
	{
		free(buf);
		return (NULL);
	}
	while (buf[i] != '\n')
		i++;
	new_buf = (char *)malloc(sizeof(char) * (ft_count(buf) - i));
	if (!new_buf)
		return (NULL);
	i = 0;
	while (buf[j])
		new_buf[i++] = buf[j++];
	new_buf[i] = '\0';
	free(buf);
	return (new_buf);
}
