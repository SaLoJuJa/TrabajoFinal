#pragma once
#include <iostream>
using namespace System::Drawing;

class Character
{
public:
	Character(int width, int height) 
	{
		this->width = width;
		this->height = height;
		idx = idy = 0;
		indexRec = -1;
	}
	~Character() {}

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

	void draw(Graphics^ g, Bitmap^ bmp)
	{
		Pen^ p = gcnew Pen(Color::Blue, 3);
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.2, height * 1.2);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
		g->DrawRectangle(p, zoom);
	}
	virtual void move(){}

protected:
	int x, y; //coordenadas de personaje
	int dx, dy; //velocidad de movimiento
	int width, height; //ancho y alto de figura
	int idx, idy; //indice de las imagenes
	int indexRec; //indice para remarcar la colision
};