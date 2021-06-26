#pragma once
#include "Character.h"
#include "Obstacle.h"
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

	Rectangle getRectangle(int x, int y)
	{
		return Rectangle(x, y, width * 1.2, height * 1.2);
	}
	
	void move(Graphics^ g, char i, vector<Obstacle*> obstacles) 
	{
		switch (i)
		{
		case 'A':
			idy = 1;
			for (int i = 0; i < obstacles.size(); i++) {
				if (this->getRectangle(x - dx, y).IntersectsWith(obstacles[i]->getRectangle())) {
					indexRec = i;
					break;
				}
			}

			if (indexRec != -1) {
				if (x > 0 && !this->getRectangle(x - dx, y).IntersectsWith(obstacles[indexRec]->getRectangle())) {
					x -= dx;
				}
			}

			else {
				if (x > 0) {
					x -= dx;
				}
			}
			break;
		case 'D':
			idy = 2;
			for (int i = 0; i < obstacles.size(); i++) {
				if (this->getRectangle(x + dx, y).IntersectsWith(obstacles[i]->getRectangle())) {
					indexRec = i;
					break;
				}
			}

			if (indexRec != -1) {
				if (x + width * 1.2 < g->VisibleClipBounds.Width && !this->getRectangle(x + dx, y).IntersectsWith(obstacles[indexRec]->getRectangle())) {
					x += dx;
				}
			}
			else {
				if (x + width * 1.2 < g->VisibleClipBounds.Width) {
					x += dx;
				}
			}
			break;
		case 'W':
			idy = 3;
			for (int i = 0; i < obstacles.size(); i++) {
				if (this->getRectangle(x, y - dy).IntersectsWith(obstacles[i]->getRectangle())) {
					indexRec = i;
					break;
				}
			}

			if (indexRec != -1) {
				if (y > 0 && !this->getRectangle(x, y - dy).IntersectsWith(obstacles[indexRec]->getRectangle())) {
					y -= dy;
				}
			}
			else {
				if (y > 0) {
					y -= dy;
				}
			}
			break;

		case 'S':
			idy = 0;
			for (int i = 0; i < obstacles.size(); i++) {
				if (this->getRectangle(x, y + dy).IntersectsWith(obstacles[i]->getRectangle())) {
					indexRec = i;
					break;
				}
			}

			if (indexRec != -1) {
				if (y + height * 1.0 < g->VisibleClipBounds.Height && !this->getRectangle(x, y + dy).IntersectsWith(obstacles[indexRec]->getRectangle())) {
					y += dy;
				}
			}
			else {
				if (y + height * 1.0 < g->VisibleClipBounds.Height) {
					y += dy;
				}
			}
			break;
		}
		idx++;
		if (idx > 2) idx = 0;
	}
private:
	int health;
};
