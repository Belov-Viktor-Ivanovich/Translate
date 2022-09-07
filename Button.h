#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include"Field.h"
using namespace sf;
using namespace std;
class Button
{
	RectangleShape button;
	Font font;
	Text text;
public:
	Button(float width, float hight, std::string text);
	void setPosition(float x, float y);
	RectangleShape& getButton();
	Text& getText();
	Vector2f getPos();
	void setColorButton(Color);
	void setPosText(float x, float y);
	
};

