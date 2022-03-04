#include <iostream>
#include <string>

#include "Graph.h"
#include "Simple_window.h"

int main()
{
	try
	{
		//window
		
		Point t1 (300, 50);
		Simple_window win(t1, 1000, 800, "My window");
		win.wait_for_button();
		
		//lines
		
		Lines grid;
		int x_size = 800;
		int y_size = 800;
		for(int i =100; i <= x_size; i+=100)
		{
			grid.add(Point(i,0), Point(i, y_size));
			grid.add(Point(0,i), Point(x_size, i));
		}
		win.attach(grid);
		win.wait_for_button();
		
		//rectangles
		
		Vector_ref<Graph_lib::Rectangle> rectangles;

		for(int i=0;i<8;i++)
		{
			rectangles.push_back(new Rectangle {Point{i*100,i*100}, 100, 100});
			rectangles[i].set_fill_color(Color::red);
			win.attach(rectangles[i]);
		}
		
		win.wait_for_button();
		
		//3 images
		
		Image i1 {Point(0,600),"dragon.jpg"};
		win.attach(i1);
		
		
		Image i2 {Point(600,0),"dragon.jpg"};
		win.attach(i2);
		
		
		Image i3 {Point(500,300),"dragon.jpg"};
		win.attach(i3);
		win.wait_for_button();
		
		//100x100 image
		
		Image p {Point(0,0),"fox.jpeg"};
		win.attach(p);
		win.set_label("fox.jpeg");
		win.wait_for_button();
		
		int y=0;
		
		while(true)
		{
			for(int i=0; i<7; i++)
			{
				p.move(100,0);
				win.wait_for_button();
			}
			
			if(y==7)
			{
				y=0;
				p.move(-700,-700);
			}
			
			else
			{
				p.move(-700,100);
				y++;
			}
			
			win.wait_for_button();
		}

	}
	catch(exception& e)
	{
		cerr << "exception: " << e.what() << endl;
		return 1;
	}
	catch(...)
	{
		cerr << "error\n";
		return 2;
	}
}
