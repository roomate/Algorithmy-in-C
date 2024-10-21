#include <stdio.h>

#include "paint.c"



void rectangle(int x_min, int y_min, int x_max, int y_max,int r, int g, int b, int largeur,int hauteur, unsigned char* pixels) {
  for (int x=x_min; x<=x_max; x++) {
      for (int y=y_min; y<=y_max; y++){
      color_pixel(x,y,r,g,b,largeur,hauteur,pixels);
    }
  }
}


int main() {
  int largeur = 600;
  int hauteur = 400;
  unsigned char* pixels = create_pixels(largeur,hauteur);
  int r = 255;
  int g = 0;
  int b = 0;
  rectangle(50,100,500,250, r, g, b, largeur, hauteur, pixels);
  

  
  /* Ecrire vers un fichier BMP */
  save_BMP("lignes.bmp", largeur, hauteur, pixels);

  /* Détruire le canvas pour libérer la mémoire */
  destroy_pixels(pixels);

  return 0 ;
}