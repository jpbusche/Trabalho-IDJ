#include "Rect.h"
#include <cstdio>

Rect::Rect(float posX, float posY, float width, float height) : x(posX), y(posY), w(width), h(height){
	x -= w / 2.0;
	y -= h / 2.0;
}

bool Rect::IsInside(float mouseX, float mouseY) {
		if(mouseX >= x && mouseX <= (x + w) && mouseY >= y && mouseY <= (y + h)) {
			return true;
		}
		return false;
}