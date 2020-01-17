#include <stdio.h>
#include "crkbd.h"

char keycounter_str[24] = {};
int total_strokes = 0;

void set_keycounter(void) {
	total_strokes++;
	snprintf(keycounter_str, sizeof(keycounter_str), "Total strokes: %d", total_strokes);
}

const char *read_keycounter(void) {
	return keycounter_str;
}
