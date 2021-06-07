#pragma once
#include "Character.h"
#include "Leader.h"
 
//FREDY ALMEYDA ♥

class Agent : public Character
{
private:
	int ind; //movimiento del enemigo
public:
	Agent(int width, int height, int ind) : Character(width, height)
	{
		this->ind = ind;
		dx = dy = 5;
		x = rand() % 60 * 10;
		y = rand() % 30 * 10;
	}
	~Agent(){}

	void move(Graphics^ g, Leader* leader)
	{
		switch (ind)
		{
		case 0:
			if (x + width * 1.0 > g->VisibleClipBounds.Width || x < 0) dx *= -1; //revote
			if (dx > 0)
			{
				idy = 2;
			}
			else
			{
				idy = 1;
			}
			x += dx;
			break;
		case 1:
			if (y + height * 1.0 > g->VisibleClipBounds.Height || y < 0)
				dy *= -1; //revote
			if (dx > 0)
			{
				idy = 1;
			}
			else
			{
				idy = 3;
			}
			y += dy;
			break;
		case 2:
			if (x == leader->getX())
			{
				x += 0;
			}
			else if (x > leader->getX())
			{
				x -= dx;
				idy = 1;
			}
			else if (x < leader->getX())
			{
				x += dx;
				idy = 2;
			}
			//y
			if (y == leader->getY())
			{
				y += 0;
			}
			else if (y > leader->getY())
			{
				y -= dy;
				idy = 3;
			}
			else if (y < leader->getY())
			{
				y += dy;
				idy = 0;
			}
		}
		idx++;
		if (idx > 3) idx = 0;
	}
};
