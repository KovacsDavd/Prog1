#include "Graph.h"
#include "Simple_window.h"
#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
try {
		Simple_window win{Point{300, 50}, 1000, 800, "My window"};
		win.wait_for_button();

		int x_size=800;
		int y_size=800;

		Lines grid;
		for (int i = 100; i < x_size+1; i+=100)
		{
			grid.add(Point{i, 0}, Point{i, y_size}); //vertical
			grid.add(Point{0, i}, Point{x_size, i}); //horizontal
			
		}
		win.attach(grid);
		win.label("My Window(grid)");
		win.wait_for_button();

		Vector_ref<Rectangle> vr;
    	for (int i = 0; i < 8; i++)
    	{
	        vr.push_back(new Rectangle{Point{i*100,i*100},100,100});
	        vr[vr.size()-1].set_fill_color(Color::red);
	        win.attach(vr[vr.size()-1]);
    	}
    	win.label("My Window(color)");
        win.wait_for_button();


		Image img1 {Point{0,200},"badge.jpg"};
		img1.set_mask(Point{0,200}, 200, 200);
		win.attach(img1);
		Image img2 {Point{200,400},"badge.jpg"};
		img2.set_mask(Point{0,200}, 200, 200);
		win.attach(img2);
		Image img3 {Point{400,600},"badge.jpg"};
		img3.set_mask(Point{0,200}, 200, 200);
		win.attach(img3);
		win.label("My Window(3 img)");
		win.wait_for_button();

		Image img_move {Point{0, 0},"badge.jpg"};
		img_move.set_mask(Point{0,200}, 100, 100);
		win.attach(img_move);
		win.label("My Window(img moving)");
		win.wait_for_button();
		while(true)
		{
        	for (int i = 0; i < 8; ++i)
        	{
        		for (int j = 0; j < 7; ++j)
        		{
        			img_move.move(100,0);
        			win.label("My Window(x+100, y+0)");
	            	win.wait_for_button();
        		}
        		if (i<7){
        			img_move.move(-700,100);
        			win.label("My Window(x-700, y+100)");
	       			win.wait_for_button();
	       		}
	       		else{
	       			img_move.move(-700,-700);
	       			win.label("My Window(x-700, y-700)");
	       			win.wait_for_button();
	       		}
	        }
    	}

} catch (exception& e){
		cerr << "exception: " << e.what() << endl;
		return 1;
	} catch(...){
		cerr << "error\n";
		return 2;
	}
}