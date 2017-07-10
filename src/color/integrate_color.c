//
// Created by Alisa Soroka on 6/18/17.
//

#include "../../rtv1.h"

int 			integrate_color(double r, double g, double b)
{
	int 		res;

	r = (r / 100) * 255;
	g = (g / 100) * 255;
	b = (b / 100) * 255;
	r = (r < 255) ? r : 255;
	g = (g < 255) ? g : 255;
	b = (b < 255) ? b : 255;
	res = ((int)r << 16) + ((int)g << 8) + (int)b;
//	return ((res < 16777215 ? res : 16777215));
//	if (res > 16777215)
//	{
//		write(1,".", 1);
//		return (16777215);
//	}
	return (res);
}