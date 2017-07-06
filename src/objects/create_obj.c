//
// Created by Alisa Soroka on 5/21/17.
//

#include "../../rtv1.h"

t_obj           *create_obj(int type_obj)
{
    t_obj       *new_obj;

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
//		new_obj->f->change_pos = 0;
//		new_obj->f->l_change_pos = 0;
		new_obj->f->chosen = 0;
		new_obj->f->for_light = 0;
//		new_obj->intersects = (t_v **)malloc(sizeof(t_v*) * (HEIGHT * WIDTH + 1));
//		new_obj->is_intersects = (double *)malloc(sizeof(double) * (HEIGHT * WIDTH + 1));
//		new_obj->l_intersct = (t_v **)malloc(sizeof(t_v*) * (HEIGHT * WIDTH + 1));
//		new_obj->l_is_intersct = (double *)malloc(sizeof(double) * (HEIGHT * WIDTH + 1));
		return (new_obj);
    }
    return (NULL);
}

void            add_obj(t_obj *first, t_obj *new_obj)
{
    t_obj       *temp;

    temp = first;
    while (temp->next)
        temp = temp->next;
    if (temp)
    	temp->next = new_obj;
}