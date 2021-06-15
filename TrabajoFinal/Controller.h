#pragma once
#include "Leader.h"
#include "Ally.h"
#include "Agent.h"
#include <vector>

using namespace std;

class Controller
{
public:
	Controller(Bitmap^ bmpLeader, Bitmap^ bmpAlly,Bitmap^ bmpAgent) 
	{
		leader = new Leader(bmpLeader->Width / 3, bmpLeader->Height / 4);
		
	}
	~Controller(){}

	void addAlly(char i,Bitmap^ bmpAlly,Bitmap^ bmpAgent)
	{
		if (i == 32)
		{
			ally.push_back(new Ally(bmpAlly->Width / 3, bmpAlly->Height / 4, rand() % 3 * 1));
			agent.push_back(new Agent(bmpAgent->Width / 3, bmpAgent->Height / 4, 0));
		}
		
	}

	void drawEverything(Graphics^ g,Bitmap^ bmpLeader, Bitmap^ bmpAlly,Bitmap^ bmpAgent)
	{
		for (int i = 0; i < ally.size(); i++)
		{
			ally[i]->draw(g, bmpAlly);	 
			agent[i]->draw(g, bmpAgent);
		}
		leader->draw(g, bmpLeader);
	}

	void moveEverything(Graphics^ g)
	{
		for (int i = 0; i < ally.size(); i++)
		{
			ally[i]->move(g);
		}
		for (int i = 0; i < ally.size(); i++)
		{
			agent[i]->move(g, ally[i]);
		}
		
	}

	Leader* getLeader() { return leader; }

private:
	Leader* leader;
	vector<Agent*> agent;
	vector<Ally*> ally;
};
