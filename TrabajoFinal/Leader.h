#pragma once
#include "Character.h"
#include <vector>

using namespace std;
using namespace System::Drawing;

class Leader : public Character
{
public:
	Leader(int width,int height) : Character(width,height)
	{
		dx = dy = 5;
		x = y = 70;
	}
	~Leader() {}
	
	void move(Graphics^ g, char i) 
	{
		switch (i)
		{
		case 'A':
			if (x > 0) {
				x -= dx;
				idy = 1;
			}
			break;
		case 'D':
			if (x + width * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				idy = 2;
			}
			break;
		case 'W':
			if (y > 0) {
				y -= dy;
				idy = 3;
			}
			break;

		case 'S':
			if (y + height * 1.0 < g->VisibleClipBounds.Height) {
				y += dy;
				idy = 0;
			}
			break;
		}
		idx++;
		if (idx > 2) idx = 0;
	}
private:
	int health;
};
