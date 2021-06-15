#pragma once
#include "Character.h"

class Ally : public Character
{
private:
	int ind; //movimiento del aliado
public:
	Ally(int width, int height, int ind) : Character(width, height)
	{
		this->ind = ind;
		dx = dy = 5;
		x = rand() % 60 * 10;
		y = rand() % 30 * 10;
	}
	~Ally(){}

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
		}
		idx++;
		if (idx > 2) idx = 0;
	}
};
