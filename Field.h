#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include"Button.h"
using namespace sf;
using namespace std;
class Field
{
	RectangleShape field;
	Font font;
	Text text;
	int sizeStr = 0;
public:
	Field(float width, float hight);
	void setPosition(float width, float hight);
	RectangleShape getField();
	Text& getText();
	void setField(String str);
	int getSizeStr();
	void setSizeStr(int size);
	String getTextToString();
	void setOutlineThickness(int a);
	void setOutlineCol(Color color);
	
};

