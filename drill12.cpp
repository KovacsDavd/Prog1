#include "Graph.h"
#include "Simple_window.h"
#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
try {
		Simple_window win{Point{100,100}, 600, 400, "My windows"}; //600*400-as ablak jön létre My window néven, TL:100-100-nál kezdődik
		win.wait_for_button(); //gomb nyomásra vár

		Axis xa{Axis::x, Point{50,300}, 500, 10, "x axis"}; //x tengely 50-300-nál kezdődik, 500px hosszú, 10 bevágás
		win.attach(xa); //hozzácsatolja 'xa'-t a 'win' ablakhoz
		win.set_label("My window #2"); //cím beállítása
		win.wait_for_button();

		Axis ya{Axis::y, Point{50,300}, 280, 10, "y axis"};
		ya.set_color(Color::blue);
		ya.label.set_color(Color::red);
		win.attach(ya);
		win.set_label("My window #3");
		win.wait_for_button();

		Function sine{sin, 0, 50, Point{50, 150}, 1200, 10, 10}; //sin fg, range:0-50(x), 50:150-nél kezdődik, 1200 pont, 10-10: ennyivel van beszorozva az x-y érték
		sine.set_color(Color::blue);
		win.attach(sine);
		win.set_label("My window #4");
		win.wait_for_button();

		Polygon poly;
		poly.add(Point{300, 200});
		poly.add(Point{350, 100});
		poly.add(Point{400, 200});

		poly.set_color(Color::red);
		poly.set_style(Line_style::solid);
		win.attach(poly);
		win.set_label("My window #5");
		win.wait_for_button();

		Rectangle r{Point{200, 200}, 100, 50}; // 100*50-es téglalap
		win.attach(r);
		win.set_label("My window #6");
		win.wait_for_button();

		Closed_polyline poly_rect; //hasonló Rectanglehez
		poly_rect.add(Point{100, 50});
		poly_rect.add(Point{200, 50});
		poly_rect.add(Point{200, 100});
		poly_rect.add(Point{100, 100});
		poly_rect.add(Point{50, 75});
		win.attach(poly_rect);
		win.set_label("My window #6.1");
		win.wait_for_button();

		r.set_fill_color(Color::yellow);
		poly.set_style(Line_style(Line_style::dash, 4));
		poly_rect.set_style(Line_style(Line_style::dash, 1));
		poly_rect.set_fill_color(Color::green);
		win.set_label("My window #7");
		win.wait_for_button();

		Text t{Point{150, 150}, "Hello, graphical world!"};
		win.attach(t);
		win.set_label("My window #8");
		win.wait_for_button();

		t.set_font(Font::times_bold_italic);
		t.set_font_size(20);
		win.set_label("My window #9");
		win.wait_for_button();

		Image ii{Point{100, 50}, "badge.jpg"};
		win.attach(ii);
		win.set_label("My window #10");
		win.wait_for_button();

		ii.move(100,200); //az eredeti helyről ennyivel tolja arrébb
		win.set_label("My window #11");
		win.wait_for_button();

		Circle c{Point{100, 200}, 100};
		Ellipse e{Point{100, 200}, 75, 25};
		e.set_color(Color::cyan);
		Mark m{Point{100, 200}, 'P'};

		ostringstream oss;
    	oss << "screen size: " << x_max() << "*" << y_max()
    		<< "; window size: " << win.x_max() << "*" << win.y_max();
    	Text sizes {Point{100,20},oss.str()};

    	Image cal{Point{225, 225}, "badge.jpg"};
    	cal.set_mask(Point{40, 40}, 300, 100); //eredeti képhez nézve: 40-40 helyre teszi, levágja 300*100-as ra

		win.attach(c);
		win.attach(m);
		win.attach(e);
		win.set_label("My window #12");
		win.wait_for_button();

		win.attach(sizes);
		win.attach(cal);
		win.set_label("My window #13");
		win.wait_for_button();




} catch (exception& e){
		cerr << "exception: " << e.what() << endl;
		return 1;
	} catch(...){
		cerr << "error\n";
		return 2;
	}
}
