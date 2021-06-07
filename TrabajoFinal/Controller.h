#pragma once
#include "Leader.h"
#include "Agent.h"
#include <vector>

using namespace std;

class Controller
{
public:
	Controller(Bitmap^ bmpLeader, Bitmap^ bmpAgent) 
	{
		leader = new Leader(bmpLeader->Width / 3, bmpLeader->Height / 4);
		for (int i = 0; i < 2; i++)
		{
			agent.push_back(new Agent(bmpAgent->Width / 3, bmpAgent->Height / 4, 0));
			agent.push_back(new Agent(bmpAgent->Width / 3, bmpAgent->Height / 4, 1));
		}
		agent.push_back(new Agent(bmpAgent->Width / 3, bmpAgent->Height / 4, 2));
	}
	~Controller(){}

	void drawEverything(Graphics^ g,Bitmap^ bmpLeader, Bitmap^ bmpAgent)
	{
		for (int i = 0; i < agent.size(); i++)
		{
			agent[i]->draw(g, bmpAgent);
		}
		leader->draw(g, bmpLeader);
	}

	void moveEverything(Graphics^ g)
	{
		for (int i = 0; i < agent.size(); i++)
		{
			agent[i]->move(g, leader);
		}
	}

	Leader* getLeader() { return leader; }

private:
	Leader* leader;
	vector<Agent*>agent;
};
