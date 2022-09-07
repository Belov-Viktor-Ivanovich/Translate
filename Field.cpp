#include "Field.h"

Field::Field(float width, float hight):field (Vector2f(width,hight))
{
	font.loadFromFile("C:\\Users\\Марина\\Documents\\Белов C++\\prog\\arial.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(24);
	field.setFillColor(sf::Color::White);
	field.setOutlineThickness(3);
	field.setOutlineColor(sf::Color::Blue);
}

void Field::setPosition(float width, float hight)
{
	field.setPosition(width, hight);
	text.setPosition(width , hight );
}

RectangleShape Field::getField()
{
	return field;
}

Text& Field::getText()
{
	return text;
}



void Field::setField(String str)
{
	text.setString(str);
}

int Field::getSizeStr()
{
	return sizeStr;
}

void Field::setSizeStr(int size)
{
	this->sizeStr = size;
}

String Field::getTextToString()
{
	return text.getString();
}

void Field::setOutlineThickness(int a)
{
	field.setOutlineThickness(a);
}

void Field::setOutlineCol(Color color)
{
	field.setOutlineColor(color);
}

String Field::getFieldStr()
{
	return text.getString();
}




