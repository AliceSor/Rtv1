//
// Created by Alisa Soroka on 6/18/17.
//

int 			integrate_color(double r, double g, double b)
{
	int 		res;

	r = (r / 100) * 255;
	g = (g / 100) * 255;
	b = (b / 100) * 255;
	res = ((int)r << 16) + ((int)g << 8) + (int)b;
	return (res);
}