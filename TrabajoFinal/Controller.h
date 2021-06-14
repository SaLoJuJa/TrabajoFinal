#pragma once
#include "Leader.h"
#include "Ally.h"
#include <vector>

using namespace std;

class Controller
{
public:
	Controller(Bitmap^ bmpLeader, Bitmap^ bmpAlly) 
	{
		leader = new Leader(bmpLeader->Width / 3, bmpLeader->Height / 4);
		for (int i = 0; i < 1; i++)
		{
			ally.push_back(new Ally(bmpAlly->Width / 3, bmpAlly->Height / 4, 0));
			ally.push_back(new Ally(bmpAlly->Width / 3, bmpAlly->Height / 4, 1));
		}
	}
	~Controller(){}

	void drawEverything(Graphics^ g,Bitmap^ bmpLeader, Bitmap^ bmpAlly)
	{
		for (int i = 0; i < ally.size(); i++)
		{
			ally[i]->draw(g, bmpAlly);
		}
		leader->draw(g, bmpLeader);
	}

	void moveEverything(Graphics^ g)
	{
		for (int i = 0; i < ally.size(); i++)
		{
			ally[i]->move(g, leader);
		}
	}

	Leader* getLeader() { return leader; }

private:
	Leader* leader;
	vector<Ally*> ally;
};
