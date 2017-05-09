#include "Rect.h"
#include <cstdio>

Rect::Rect(double posX, double posY, double width, double height) : x(posX), y(posY), w(width), h(height){
	x -= w / 2.0;
	y -= h / 2.0;
}

bool Rect::IsInside(double mouseX, double mouseY) {
		if(mouseX >= x && mouseX <= (x + w) && mouseY >= y && mouseY <= (y + h)) {
			return true;
		}
		return false;
}