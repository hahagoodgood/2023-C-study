#pragma once
typedef struct rect {
	int x, y, w, h;
}RECT;

void draw_rect(const RECT*);
double calc_area(const RECT*);
void move_rect(RECT*, int, int);
