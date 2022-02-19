#include "Simple_window.h"
#include "Graph.h"
#include <string>
#include <iostream>

int main()
{
	try
	{
		//1
		
		Point t1 {100, 100};
		Simple_window win {t1, 600, 400, "My window"};
		win.wait_for_button();
		
		//2
		//Axis
		
		Axis xa {Axis::x, Point(20, 300),280, 10, "x axis"};
		win.attach(xa);
		win.set_label("x axis");
		win.wait_for_button();
		
		Axis ya {Axis::y, Point(20, 300), 280, 10, "y axis"};
		ya.set_color(Color::cyan);
		ya.label.set_color(Color::dark_red);
		
		win.attach(ya);
		win.set_label("y axis");
		win.wait_for_button();
		
		//sin
		
		Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};
		sine.set_color(Color::blue);
		win.attach(sine);
		win.set_label("Sin");
		win.wait_for_button();
		
		//polygon
		
		Polygon poly;
		poly.add(Point{300, 200});
		poly.add(Point{350, 100});
		poly.add(Point{400, 200});
		poly.set_color(Color::red);
		poly.set_style(Line_style::dash);
		win.attach(poly);
		win.set_label("Poly");
		win.wait_for_button();
		
		//rectangle
		
		Rectangle r {Point(200, 200), 100, 50};
		win.attach(r);
		win.set_label("Rectangle");
		win.wait_for_button();
		
		//closed polyline
		
		Closed_polyline poly_rect;
		poly_rect.add(Point{100, 50});
		poly_rect.add(Point{200, 50});
		poly_rect.add(Point{200, 100});
		poly_rect.add(Point{100, 100});
		poly_rect.add(Point{75, 75});
		
		win.attach(poly_rect);
		win.set_label("Closed polyline");
		win.wait_for_button();
		
		//fill
		
		poly_rect.set_fill_color(Color::green);
		poly_rect.set_style(Line_style(Line_style::dash, 2));
		poly.set_style(Line_style(Line_style::dash, 4));
		r.set_fill_color(Color::yellow);
		
		win.set_label("Fill");
		win.wait_for_button();
		
		//text
		
		Text t {Point{150, 150}, "Hello, graphical world!"};
		win.attach(t);
		win.set_label("Text");
		win.wait_for_button();
		
		t.set_font(Font::times_bold);
		t.set_font_size(20);
		
		//image
		
		Image ii {Point(100, 50), "badge.jpg"};
		win.attach(ii);
		win.set_label("Image");
		win.wait_for_button();
		
		ii.move(100, 200);
		win.set_label("Image #2");
		win.wait_for_button();
		
		//etc
		
		Circle c {Point{100,200},50};
		Ellipse e {Point{100,200}, 75,25};
		e.set_color(Color::dark_red);
		Mark m {Point(100,200),'x'};
		
		ostringstream oss;
		oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*" << win.y_max();
		Text sizes {Point{100,20},oss.str()};
		
		Image cal {Point{225,225},"badge.jpg"};
		cal.set_mask(Point{40,40},200,150);                      // display center part of image
		
		win.attach(c);
		win.attach(m);
		win.attach(e);
		win.attach(sizes);
		win.attach(cal);
		win.set_label("Etc");
		win.wait_for_button();
		
		//3
		
		xa.set_color(Color::cyan);
		sine.set_style(Line_style(Line_style::dash, 6));
		poly.set_color(Color::black);
		r.set_style(Line_style::dash);
		poly_rect.add(Point{50, 50});
		t.set_font_size(10);
		ii.move(100, 150);
		
		win.attach(xa);
		win.attach(sine);
		win.attach(poly);
		win.attach(r);
		win.attach(poly_rect);
		win.attach(t);
		win.attach(ii);
		
		win.set_label("Changes");
		win.wait_for_button();
	}
	 catch(exception& e)
	{
	cerr << "exception: " << e.what() << '\n';
		return 1;
	}
	catch(...)
	{
		cerr << "error\n";
		return 2;
	}
}
