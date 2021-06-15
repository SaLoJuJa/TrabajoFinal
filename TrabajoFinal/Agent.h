#pragma once
#include "Character.h"
#include "Ally.h"

class Agent : public Character
{
public:
	Agent(int width, int height, int ind) : Character(width,height) 
	{
		this->ind = ind;
		dx = dy = 1;
		x = rand() % 60 * 10;
		y = rand() % 30 * 10;
	}
	~Agent() {}

	void move(Graphics^ g, Ally* ally)
	{
		switch (ind)
		{
		case 0:
			if (x == ally->getX())
				x += 0;
			else if (x > ally->getX())
			{
				x -= dx;
				idy = 1;
			}
			else if (x < ally->getX())
			{
				x += dx;
				idy = 2;
			}

			if (y == ally->getY())
				y += 0;
			else if (y > ally->getY())
			{
				y -= dy;
				idy = 3;
			}
			else if (y < ally->getY())
			{
				y += dy;
				idy = 0;
			}
		}
		idx++;
		if (idx > 2)idx = 0;
	}

private:
	int ind;
};
