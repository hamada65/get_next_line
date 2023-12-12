/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:45:54 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/12 15:52:25 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

int	search_line(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->buff[i] && i < BUFFER_SIZE)
		{
			if (lst->buff[i] == '\n')
			{
				return (1);
			}
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

int	ft_lstsize(t_list *lst)
{
	int	num;

	num = 0;
	while (lst)
	{
		lst = lst->next;
		num++;
	}
	return (num);
}

int	check_node(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	del_nodes(t_list **lst)
{
	t_list	*tmp;
	int		i;
	int		len;

	while (*lst)
	{
		if (!check_node((*lst)->buff))
		{
			free((*lst)->buff);
			tmp = (*lst)->next;
			free((*lst));
			*lst = tmp;
		}
		else
		{
			i = 0;
			len = ft_strlen((*lst)->buff);
			while ((*lst)->buff[i])
			{
				if ((*lst)->buff[i] == '\n')
				{
					i++;
					trim_word((*lst)->buff, ((*lst)->buff) + i, len - i);
					return ;
				}
				i++;
			}
		}
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	trim_word(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}