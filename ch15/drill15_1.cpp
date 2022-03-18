#include "Simple_window.h"
#include "Graph.h"
#include <string>
#include <iostream>

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x) + slope(x);}

int main()
{
	Point t1 {100, 100};
	Simple_window win {t1, 600, 600, "Function graphs"};
	
	Axis xa {Axis::x, Point(100,300), 400, 20, "1==20 pixels"};
	xa.set_color(Color::red);
	win.attach(xa);
	
	Axis ya {Axis::y, Point(300,500), 400, 20, "1==20 pixels"};
	ya.set_color(Color::red);
	win.attach(ya);
	
	constexpr int min = -10;
	constexpr int max = 11;
	constexpr int points = 400;
	
	constexpr int x = 20;
	constexpr int y = 20;
	
	const Point o {300, 300};
	
	Function f1 {one, min, max, o, points, x, y};
	Function f2 {slope, min, max, o, points, x, y};
	Function f3 {square, min, max, o, points, x, y};
	Function f4 {cos, min, max, o, points, x, y};
	f4.set_color(Color::blue);
	Function f5 {sloping_cos, min, max, o, points, x, y};
	Text t {Point{100,390},"x/2"};
	
	win.attach(f1);
	win.attach(f2);
	win.attach(t);
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);
	
	win.wait_for_button();
}
