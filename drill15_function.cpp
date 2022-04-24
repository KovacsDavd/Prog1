#include "Graph.h"
#include "Simple_window.h"
#include <string>
#include <iostream>

using namespace Graph_lib;

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x) + slope(x);}


int main(){
	Simple_window win{Point{500,250}, 600, 600, "Function graphs"}; //600*600-as ablak jön létre  Function graphs néven, Pointnál kezdődik
	win.wait_for_button(); //gomb nyomásra vár

	Axis xa{Axis::x, Point{100,300}, 400, 20, "x axis"}; //x tengely Point-nál kezdődik, 400px hosszú, 20 bevágás
	xa.set_color(Color::red);
	win.attach(xa);

	Axis ya{Axis::y, Point{300,500}, 400, 20, "y axis"};
	ya.set_color(Color::red);
	win.attach(ya);

	win.set_label("1==20pixels");
	win.wait_for_button();
	
	int x_scale = 20;
	int y_scale = 20;
	int min_range = -10;
	int max_range = 10;
	Point point = Point{300, 300};
	int length = 400;

	//function: one fg, range:min-max(x), Point-nél kezdődik, lengt hosszu(px), x_sclale, y_scale: ennyivel van beszorozva az x-y érték
	Function func(one, min_range, max_range, point, length, x_scale, y_scale);
	Text tslope(Point{100, 270}, "x");
	win.attach(tslope);
	win.attach(func);
	win.set_label("One graph");
	win.wait_for_button();

	Function func2(slope, min_range, max_range, point, length, x_scale, y_scale);
	win.attach(func2);
	Text tslope2(Point{100, 380}, "x/2");
	win.attach(tslope2);
	win.set_label("Slope graph");
	win.wait_for_button();

	Function func3(square, min_range, max_range, point, length, x_scale, y_scale);
	win.attach(func3);
	Text tslope3(Point{220, 200}, "x*x");
	win.attach(tslope3);
	win.set_label("Square graph");
	win.wait_for_button();

	Function func4(cos, min_range, max_range, point, length, x_scale, y_scale);
	func4.set_color(Color::blue);
	Text tslope4(Point{50, 320}, "cos(x)");
	win.attach(tslope4);
	win.attach(func4);
	win.set_label("Cos graph");
	win.wait_for_button();
	
	Function func5(sloping_cos, min_range, max_range, point, length, x_scale, y_scale);
	Text tslope5(Point{100, 430}, "cos(x)+slope()");
	win.attach(tslope5);
	win.attach(func5);
	win.set_label("Cos+slope graph");
	win.wait_for_button();
}
