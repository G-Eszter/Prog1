#include "Window.h"
#include "Graph.h"
#include "GUI.h"

namespace Graph_lib
{
	Window::Window(int ww, int hh, const string& title)
	:Fl_Window(ww, hh, title.c_str()), w(ww), h(hh)
	{
		init();
	}
	
	Window::Window(Point xy, int ww, int hh, const string& title)
	:Fl_Window(xy.x, xy.y, ww, hh, title.c_str()), w(ww), h(hh)
	{
		init();
	}
	
	void Window::init()
	{
		resizable(this);
		show();
	}
	
	void Window::draw()
	{
		Fl_Window::draw();
		for (unsigned int i=0; i < shape.size(); ++i) shapes[i] ->draw();
	}
	
	void Window::attach(Shape& s)
	{
		shapes.push_back(&s);
	}
	
	void Window::detach(Shape& s)
	{
		for(unsigned int i=shapes.size(); i>0; --i)
			if (shapes[i-1] == &s)
			shapes.erase(shapes.begin()+(i-1));
	}
	
	void Window::attach(Widget& w)
	{
		begin();
			w.attach(*this);
		end();
	}
	
	void Window::detach(Widget& w)
	{
		w.hide();
	}
	
	int gui_main() { return Fl::run();}
}
