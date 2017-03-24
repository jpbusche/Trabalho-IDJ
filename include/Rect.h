#ifndef RECT_H
#define RECT_H

using namespace std;

class Rect {
	public:
		float x;
		float y;
		int w;
		int h;

		Rect(float x, float y, float w ,float h);

		bool IsInside(float mouseX, float mouseY);
};

#endif