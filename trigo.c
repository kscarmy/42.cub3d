#include <math.h>
#include <stdio.h>
// Convert to radian
// Return Double

/*
adjacent : b
opposite : a
hypotenus : c

soh cah toa

sinus     = a / c
cosinus   = b / c
tan       = a / b


a = sinus * c
b = cosinus * c
*/

double convert_to_radian(double degree)
{
	return(degree * ( M_PI / 180.0 ));
}

double find_x(double d, double h)
{
	return((double)cos((double)convert_to_radian(d)) * h);
}

double find_y(double d, double h)
{
	return((double)sin((double)convert_to_radian(d)) * h);
}

int main()
{
	double d;
	double h;
	double x;
	double y;
	
	d = 0.112500;
	h = 100;
	x = find_x(d, h);
	y = find_y(d, h);
	printf("x = %f\ny = %f\n", x, y);
	return (0);
}
