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

		//paredes
		obstacles.push_back(new Obstacle(135, 100, 15, 363));
		obstacles.push_back(new Obstacle(153, 264, 675, 15));
		obstacles.push_back(new Obstacle(828, 100, 15, 363));
		obstacles.push_back(new Obstacle(154, 100, 117, 15));
		obstacles.push_back(new Obstacle(423, 17, 15, 165));
		obstacles.push_back(new Obstacle(610, 100, 15, 165));
		obstacles.push_back(new Obstacle(152, 447, 185, 15));
		obstacles.push_back(new Obstacle(422, 447, 220, 15));
		obstacles.push_back(new Obstacle(323, 465, 15, 110));
		obstacles.push_back(new Obstacle(625, 465, 15, 110));
		//bordes del mapa
		obstacles.push_back(new Obstacle(18, 15, 1048, 1));
		obstacles.push_back(new Obstacle(15, 575, 1048, 1));
		obstacles.push_back(new Obstacle(1065, 15, 1, 561));
		obstacles.push_back(new Obstacle(18, 15, 1, 561));
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
			a->move(g,getObstacles());
		}
		for (int i = 0; i < nAgents; i++)
		{
			agent[i]->move(g, ally[i]);
		}
			
	}

	Leader* getLeader() { return leader; }
	int getTime() { return time; }
	void decreaseTime() { time--; }
	vector<Obstacle*> getObstacles() { return obstacles; }

private:
	Leader* leader;
	vector<Agent*> agent;
	vector<Ally*> ally;
	vector<Obstacle*> obstacles;
	int time, nAgents, nAllys, nHabitants;
};
