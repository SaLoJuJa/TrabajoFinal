#pragma once
#include "Leader.h"
#include "Ally.h"
#include "Agent.h"
#include <vector>

using namespace std;

class Controller
{
public:
	Controller(Bitmap^ bmpLeader, Bitmap^ bmpAlly,Bitmap^ bmpAgent, 
		int time, int nAgents, int nAllys, int nHabitants)
	{
		this->nAgents = nAgents;
		this->nAllys = nAllys;
		this->nHabitants = nHabitants;

		this->time = time;
		leader = new Leader(bmpLeader->Width / 3, bmpLeader->Height / 4);

		for (int i = 0; i < nAllys; i++)
			ally.push_back(new Ally(bmpAlly->Width / 3, bmpAlly->Height / 4, rand() % 3 * 1));

		for (int i = 0; i < nAgents; i++)
			agent.push_back(new Agent(bmpAgent->Width / 3, bmpAgent->Height / 4, 0));

	}
	~Controller(){}

	void drawEverything(Graphics^ g,Bitmap^ bmpLeader, Bitmap^ bmpAlly,Bitmap^ bmpAgent)
	{
		for each (Ally * a in ally)
		{
			a->draw(g, bmpAlly);
		}
		for each (Agent * a in agent)
		{
			a->draw(g, bmpAgent);
		}
		leader->draw(g, bmpLeader);
	}

	void moveEverything(Graphics^ g)
	{
		for each (Ally * a in ally)
		{
			a->move(g);
		}
		for (int i = 0; i < nAgents; i++)
		{
			agent[i]->move(g, ally[i]);
		}
			
	}

	Leader* getLeader() { return leader; }
	int getTime() { return time; }
	void decreaseTime() { time--; }

private:
	Leader* leader;
	vector<Agent*> agent;
	vector<Ally*> ally;
	int time, nAgents, nAllys, nHabitants;
};
