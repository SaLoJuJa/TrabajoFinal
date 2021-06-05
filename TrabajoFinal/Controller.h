#pragma once
#include "Leader.h"
#include <vector>

using namespace std;

class Controller
{
public:
	Controller(Bitmap^ bmpLeader) 
	{
		leader = new Leader(bmpLeader->Width / 3, bmpLeader->Height / 4);
	}
	~Controller(){}

	void drawEverything(Graphics^ g,Bitmap^ bmpLeader)
	{
		leader->draw(g, bmpLeader);
	}

	Leader* getLeader() { return leader; }

private:
	Leader* leader;
};
