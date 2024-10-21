#include <stdio.h>

#include "paint.c"
 
 #include <math.h>

int compter_iterations( double x, double y, int max_iter) {
	double a=0;
	double b=0;
	double c=0;
	int n=0;
	while ( a*a + b*b <=4 ) {
		c=a*b;
		a=a*a - b*b + x;
		b=2*c + y;
		n+=1;
		if (n>=max_iter) {
			return max_iter;
		}
	}return n;
}

int main(void) {
	double largeur = 600;
	double hauteur = 400;
	double x_left = -2;
	double y_top= 1;
	double x_width = 3;
	double y_height = x_width*hauteur/largeur;
	unsigned char* pixels = create_pixels(largeur,hauteur);
	double max_iter=100;
	double k = 0;
	double x=0;
	double y=0;
	for (double i = 0; i<=largeur; i++) {
		for (double j = 0; j<=hauteur; j++) {
			x = x_left + i * x_width / (largeur - 1);
			y = y_top - j * y_height / (hauteur - 1);
			k=compter_iterations(x,y, max_iter);
			double r=255*sqrt(sin(k/max_iter));
			double g=255-r;
			double b=0;
			if (k==max_iter) {
				r=0;
				b=0;
			} 
			color_pixel(i,j,r,g,b,largeur,hauteur,pixels);
		}
	}
	save_BMP("mandelbrot.bmp", largeur, hauteur, pixels);
	destroy_pixels(pixels);
	return 0;
}

