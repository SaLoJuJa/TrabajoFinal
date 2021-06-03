#pragma once

using namespace System::Drawing;

class Character
{
public:
	Character() {}
	~Character() {}

	virtual void move() {}
	virtual void draw() {}

	int getX() { return x; }
	int getY() { return y; }
	int getDx() { return dx; }
	int getDy() { return dy; }
	int getWidth() { return width; }
	int getHeight() { return height; }

	void setX(int n) { x = n; }
	void setY(int n) { y = n; }
	void setDx(int n) { dx = n; }
	void setDy(int n) { dy = n; }
	void setWidth(int n) { width = n; }
	void setHeight(int n) { height = n; }

protected:
	int x, y; //coordenadas de personaje
	int dx, dy; //velocidad de movimiento
	int width, height; //ancho y alto de figura

};