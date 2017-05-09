#ifndef RECT_H
#define RECT_H

using namespace std;

class Rect {
	public:
		double x;
		double y;
		double w;
		double h;

		Rect(double x, double y, double w ,double h);

		bool IsInside(double mouseX, double mouseY);
};

#endif