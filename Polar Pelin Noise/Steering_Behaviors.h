#pragma once
#include <vector>
#include "Circle.h"
#include <fstream>
using namespace std;

class Steering_Behaviors
{
	std::vector<Circle> s;
	ofstream ofile;
	ifstream ifile;
	
public:

	Steering_Behaviors();
	void get();

	void draw();
	void update();

	~Steering_Behaviors();
};

