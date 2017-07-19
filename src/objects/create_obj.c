/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:40:46 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/19 14:40:47 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

t_obj			*create_obj(int type_obj)
{
	t_obj		*new_obj;

	new_obj = (t_obj *)malloc(sizeof(t_obj) + 1);
	if (new_obj)
	{
		new_obj->type_obj = type_obj;
		new_obj->cl = NULL;
		new_obj->p = NULL;
		new_obj->s = NULL;
		new_obj->cn = NULL;
		new_obj->next = NULL;
		new_obj->f = (t_flags *)malloc(sizeof(t_flags) + 1);
		new_obj->f->chosen = 0;
		new_obj->f->for_light = 0;
		new_obj->f->is_visible = 1;
		return (new_obj);
	}
	return (NULL);
}

void			add_obj(t_obj *first, t_obj *new_obj)
{
	t_obj		*temp;

	temp = first;
	while (temp->next)
		temp = temp->next;
	if (temp)
		temp->next = new_obj;
}
