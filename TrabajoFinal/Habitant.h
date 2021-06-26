#pragma once
#include "Character.h"

class Habitant : public Character
{
public:
	Habitant (int width, int height, int ind) : Character (width, height)
	{
		this->ind = ind;
		dx = dy = 5;
		x = rand() % 80 * 10;
		y = rand() % 80 * 10;
	}
	~Habitant(){}

	void move(Graphics^ g)
	{
		switch (ind)
		{
		case 1: //Horizontal

			if (x + width * 1.2 > g->VisibleClipBounds.Width || x < 0) dx *= -1; //Rebote
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
		case 2:	//Vertical
			if (y + height * 1.2 > g->VisibleClipBounds.Height || y < 0) //Rebote
				dy *= -1;
			if (dy > 0)
			{
				idy = 0;
			}
			else
			{
				idy = 3;
			}
			y += dy;
			break;
		default:
			break;
		}
		idx++;
		if (idx > 2)idx = 0;
	}

private:
	int ind;
};