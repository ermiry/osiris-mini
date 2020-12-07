#include <stdlib.h>

float three_way_max (float a, float b, float c) {

	return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;

}

float three_way_min (float a, float b, float c) {

	return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;

}