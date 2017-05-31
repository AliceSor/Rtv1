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
        new_obj->next = NULL;
        return (new_obj);
    }
    exit(1);
}

void            *add_obj(t_obj *first, t_obj *new_obj)
{
    t_obj       *temp;

    temp = first;
    while(temp->next)
        temp = temp->next;
    if (temp)
    temp->next = new_obj;
}