#pragma once

using namespace System::Drawing;

class Obstacle {
private:
	int x, y;
	int width, height;

public:
	Obstacle(int x, int y, int width, int height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	~Obstacle() {}

	void draw(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::Red, 3);
		g->DrawRectangle(p, getRectangle());
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width, height);
	}

};