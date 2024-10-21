#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool fix_point(int* T,int n) {
	if (n==0) return false;
	if (T[0]==0) return true;
	return false;
}

bool move_bishop(int x, int y, int w, int z) {
	if (w<0 || w>7 || z<0 || z>7 || x<0 || z<0 || x>7 || z>7) return false;
	if  (abs(z-y)==abs(w-x)) return true;
	return false;
}






bool move_knight(int x, int y, int w, int z) {
	if (w<0 || w>7 || z<0 || z>7 || x<0 || z<0 || x>7 || z>7) return false;
	if (abs(w-x)==1) {
		return (abs(z-y)==2);
	}
	if (abs(w-x)==2) {
		return (abs(z-y)==1);
	}
	return false;
}

int main(int argc, char* argv[]) {
	move_knight(atoi(argv[1]),atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
	return 0;
}