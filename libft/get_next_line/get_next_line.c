/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 01:40:54 by emenella          #+#    #+#             */
/*   Updated: 2020/12/01 04:10:58 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_buffer_to_line(t_gnl *current, char **line, t_gnl **alst)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (ft_strchr(current->content, '\n'))
	{
		tmp = ft_strdup(current->content);
		while (tmp && tmp[i] != '\n')
			i++;
		j = i + 1;
		while (current->content[i])
			current->content[i++] = '\0';
		*line = ft_strdup(current->content);
		free(current->content);
		current->content = ft_strdup(&tmp[j]);
		if (!current->content)
			return (-1);
		free(tmp);
		return (1);
	}
	*line = ft_strdup(current->content);
	ft_gnlfree(current, alst);
	return (0);
}

void	ft_gnlfree(t_gnl *lst, t_gnl **alst)
{
	t_gnl	*tmp;

	tmp = *alst;
	while (tmp && tmp != lst)
	{
		if (tmp->next == lst)
			tmp->next = lst->next;
		tmp = tmp->next;
	}
	if (lst == *alst)
		*alst = lst->next;
	free(lst->content);
	lst->content = NULL;
	free(lst);
	lst = NULL;
}

t_gnl	*ft_gnlchr(int fd, t_gnl **alst)
{
	t_gnl	*tmp;

	tmp = *alst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	int		j;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!result)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		result[i] = s1[i];
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

int	get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static t_gnl	*alst;
	t_gnl			*current;
	int				readed;

	readed = 1;
	if (!line || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (-1);
	if (!alst)
		alst = ft_gnlnew(fd);
	current = ft_gnlchr(fd, &alst);
	if (!current)
	{
		ft_gnladd_back(&alst, fd);
		current = ft_gnlchr(fd, &alst);
	}
	while (!ft_strchr(current->content, '\n') && readed > 0)
	{
		readed = read(current->fd, buffer, BUFFER_SIZE);
		buffer[readed] = '\0';
		current->content = ft_strjoin_free(current->content, buffer);
	}
	return (ft_buffer_to_line(current, line, &alst));
}
