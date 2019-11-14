#include "Steering_Behaviors.h"


Steering_Behaviors::Steering_Behaviors()
{
	ifile.open("cac.txt");
	//ofile.open("cac.txt");

	for(int i = 0 ; i  < 95;i++)
	{
		Vector2f m;
		ifile >> m.x >> m.y;
		s.push_back(Circle(m));

		string line;
		getline(ifile,line);
	}
}

void Steering_Behaviors::get()
{
	if(Mouse::isButtonPressed(Mouse::Left))
	{
		Vector2f mouse = (Vector2f)Mouse::getPosition(*window);
		s.push_back(Circle(mouse));
		ofile << mouse.x << " " << mouse.y << endl;
	}
	else if(Mouse::isButtonPressed(Mouse::Right))
	{
		
	}
}

void Steering_Behaviors::draw()
{
	for(auto &i : s)
	{
		i.draw();
	}
}

void Steering_Behaviors::update()
{
	for (auto& i : s)
	{
		i.update();
	}
}


Steering_Behaviors::~Steering_Behaviors()
{
	ofile.close();
	ifile.close();
}
