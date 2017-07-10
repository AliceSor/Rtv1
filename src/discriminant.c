//
// Created by Alisa Soroka on 5/26/17.
//

#include "../rtv1.h"

int	        	discriminant(double *t, t_abc abc)
{
    abc.d = abc.b * abc.b - 4 * abc.a * abc.c;
    if (abc.d < 0)
        return (0);
    abc.c = sqrt(abc.d);
    abc.t0 = (-abc.b + abc.c) / (2 * abc.a);
    abc.t1 = (-abc.b - abc.c) / (2 * abc.a);
    if (abc.t0 < 0.001f && abc.t1 < 0.001f)
        return (0);
    else if (abc.t0 > 0.001f && abc.t1 > 0.001f && abc.t0 > abc.t1)
        abc.t0 = abc.t1;
    else if (abc.t0 < 0.001f)
        abc.t0 = abc.t1;
    if (abc.t0 > 0.001f)
    {
        *t = abc.t0;
        return (1);
    }
    return (0);
}

//int		complicated_disc(float a, float b, float c, t_rtv *mst)
//{
//    float t0;
//    float t1;
//
//    c = sqrt(mst->discriminant);
//    t0 = (-b + c) / (2 * a);
//    t1 = (-b - c) / (2 * a);
//    if (t0 < 0.001f && t1 < 0.001f)
//        return (0);
//    else if (t0 > 0.001f && t1 > 0.001f && t0 > t1)
//        t0 = t1;
//    else if (t0 < 0.001f)
//        t0 = t1;
//    if (t0 > 0.001f)
//    {
//        mst->discriminant = t0;
//        return (1);
//    }
//    return (0);
//}
//
//int		disc(float a, float b, float c, t_rtv *mst)
//{
//    float t0;
//    float t1;
//
//    c = sqrt(mst->disc);
//    t0 = (-b + c) / (2 * a);
//    t1 = (-b - c) / (2 * a);
//    if (t0 < 0.1f && t1 < 0.1f)
//        return (0);
//    else if (t0 > 0.1f && t1 > 0.1f && t0 > t1)
//        t0 = t1;
//    else if (t0 < 0.1f)
//        t0 = t1;
//    if (t0 > 0.1f)
//    {
//        mst->disc = t0;
//        return (1);
//    }
//    return (0);
//}