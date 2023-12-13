/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:45:54 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/13 13:54:51 by mel-rhay         ###   ########.fr       */
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
	long	i;

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

void	del_nodes(t_list **lst, size_t i)
{
	t_list	*tmp;

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
			while ((*lst)->buff[i])
			{
				if ((*lst)->buff[i] == '\n')
				{
					trim_word((*lst)->buff, ((*lst)->buff) + i + 1, i + 1);
					return ;
				}
				i++;
			}
		}
	}
}

void	trim_word(char *dst, const char *src, size_t index)
{
	size_t	i;
	size_t	len;
	size_t	size;

	len = 0;
	while (dst[len])
		len++;
	size = len - index;
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
