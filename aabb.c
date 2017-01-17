/*
 * AABB Collision Detection
 *
 * Programista
 * by Joel Enriquez
 *
 */

#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void){
	string aa = get_string();
	string bb = get_string();
	if(aa != NULL && bb != NULL){
		double ax = atof(strtok(aa, " "));
		double ay = atof(strtok(NULL, " "));
		double aw = atof(strtok(NULL, " "));
		double ah = atof(strtok(NULL, " "));
		double bx = atof(strtok(bb, " "));
		double by = atof(strtok(NULL, " "));
		double bw = atof(strtok(NULL, " "));
		double bh = atof(strtok(NULL, " "));
		double x1 = ax > bx ? ax : bx;
		double x2 = ax+aw < bx+bw ? ax+aw : bx+bw;
		double y1 = ay > by ? ay : by;
		double y2 = ay+ah < by+bh ? ay+ah : by+bh;
		printf("%.2lf\n", (x1 > x2) || (y1 > y2) ? 0.0 : (x2 - x1) * (y2 - y1));
	}

	return 0;
}
