/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/27 15:34:00 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long_bonus.h"

void	ft_lstadd_back(t_pos_list **lst, t_pos_list *new)
{
	t_pos_list	*p;

	if (lst == NULL || new == NULL)
		return ;
	p = *lst;
	if (*lst)
	{
		p = ft_lstlast(p);
		p->next = new;
	}
	else
		*lst = new;
}

t_pos_list	*ft_lstlast(t_pos_list *lst)
{
	t_pos_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp)
	{
		if (!tmp->next)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

t_pos_list	*ft_lstnew(int x, int y)
{
	t_pos_list	*new;

	new = malloc(sizeof(t_pos_list));
	if (!new)
		return (NULL);
	new->x = malloc(sizeof(int));
	new->y = malloc(sizeof(int));
	new->flag = malloc(sizeof(int));
	if (!new->x || !new->y)
		return (NULL);
	*new->flag = 0;
	*new->x = x;
	*new->y = y;
	new->next = NULL;
	return (new);
}
