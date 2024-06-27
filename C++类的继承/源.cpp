#include<iostream>
#include<math.h>
using namespace std;
#define Pi 3.14
class two_d {
public:
	double length;
	double width;
	double height;
	double r;
};                                  //二维类
class square :public two_d {
public:
	void getArea(double &s1_area) {
		cout << "input square's length:" << endl;
		cin >> length;
		s1_area = length * length;
		cout << "s1_Area:" << s1_area << endl;

	}
	double getPerimiter() {
		return length * 4;
	}
};                                 //正方形
class rectangle:public two_d {
public:
	double getArea(double &r1_area) {
		r1_area = length * width;
		return r1_area;
	}
	double getPerimiter(double length,double width) {
		return 2 * (length + width);
	}
};                                //长方形
class triangle :public two_d {
public:
	double bottom;
	double edge1, edge2;
	double getArea(double bottom,double height) {
		return (bottom * height);
	}
	double getPerimiter(double bottom, double edge1,double edge2) {
		return bottom + edge1 + edge2;
	}
};                                 //三角形
class e_triangle :public triangle {
public:
	double getArea(double edge1) {
		return sqrt(3) * edge1 / 4;
	}
	double getPerimiter(double edge1) {
		return edge1 * 3;
	}
};                                 //正三角形

class trapezoid :public two_d {
public:
	double bottom;
	double u_bottom;
	double edge1, edge2;
	double getArea(double bottom,double u_bottom,double height) {
		return (bottom + u_bottom) * height / 2;
	}
	double getPerimiter(double bottom,double u_bottom,double edge1,double edge2) {
		return (bottom + u_bottom + edge1 + edge2);
	}
};                                  //梯形


class Three_d {
public:
	double length;
	double width;
	double r;
	double height;
};                                        //三维基类
class ball :public Three_d {
public:
	double getArea(double& b1_r, double& b1_area) {
		b1_area = 4 * Pi * b1_r * b1_r;
		return b1_area;
	}
	double getVolume(double& b1_r, double& b1_volume) {
		b1_volume = 4 * Pi * r * r * r / 3;
		return b1_volume;
	}

};                                         //球
class cylinder :public Three_d {
public:
	double getArea(double& c1_area, double& c1_height, double& c1_r) {
		c1_area = c1_height * Pi * c1_r * 2;
		return c1_area;
	}
	double getVolume(double& c1_volume, double& c1_height, double& c1_r) {
		c1_volume = c1_height * Pi * c1_r * c1_r;
		return c1_volume;
	}
};                                        //圆柱体
class cuboid :public Three_d {
	double getArea(double& cu1_area, double& cu1_length, double& cu1_width, double& cu1_height) {
		cu1_area = (cu1_length * cu1_width + cu1_length * cu1_height + cu1_height * cu1_width) * 2;
		return cu1_area;
	}
	double getVolume(double& cu1_volume, double& cu1_length, double& cu1_width, double& cu1_height) {
		cu1_volume = cu1_length * cu1_width * cu1_height;
		return cu1_volume;
	}
};                                         //长方体
class cube :public Three_d {
	double getArea(double& cube1_area, double& cube1_length) {
		cube1_area = 6 * cube1_length * cube1_length;
		return cube1_area;
	} 
	double getVolume(double& cube1_volume, double& cube1_length) {
		cube1_volume = cube1_length * cube1_length * cube1_length;
		return cube1_volume;
	}
};                                          //正方体

class Triangular_prism :public Three_d {
	double getArea(double& p_area, double& p_length, double& p_width, double& p_height) {
		p_area = 3 * (p_length * p_width) + p_length * p_width;
		return p_area;
	}
	double getVolume(double p_volume, double p_length, double p_width, double p_height) {
		p_volume= (p_height * p_length * p_width) / 2;
		return p_volume;
	}
};                                         //三棱柱

class Regular_tetrahedron :public Three_d {
	double getArea(double Rt_edge, double Rt_area) {
		Rt_area = sqrt(3) * Rt_edge * Rt_edge;
		return Rt_area;
	}
	double getVolume(double Rt_volume, double Rt_edge) {
		Rt_volume = sqrt(2) * Rt_edge * Rt_edge / 12;
		return Rt_volume;
	}
};                                        //正四面体
void main() {
	square s1;
	double s1_area;
	s1.getArea(s1_area);
	cout <<"perimiter:"<< s1.getPerimiter();

	rectangle r1;
	double r1_area;
	r1.getArea(r1_area);
	
	ball b1;
	double b1_r = 5, b1_area;
	b1.getArea(b1_r, b1_area);
	cout << "ball(b1)_Area = " << b1_area;
}