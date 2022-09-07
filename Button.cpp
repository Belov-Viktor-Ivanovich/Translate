#include "Button.h"

Button::Button(float width, float hight, std::string name) : button(sf::Vector2f(width, hight))
{
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setString(name);
	text.setCharacterSize(30);
	font.loadFromFile("C:\\Users\\Марина\\Desktop\\arialbi.ttf");
	button.setFillColor(sf::Color::Green);
	//button.setOutlineColor(sf::Color(48, 48, 48));
	//button.setOutlineThickness(3);
}



void Button::setPosition(float x, float y)
{
	button.setPosition(x, y);
	text.setPosition(x+10, y);
}

sf::RectangleShape& Button::getButton()
{
	return button;
}

sf::Text& Button::getText()
{
	return text;
}



sf::Vector2f Button::getPos()
{
	return button.getPosition();
}

void Button::setColorButton(Color color)
{
	button.setFillColor(color);
}


void Button::setPosText(float x, float y)
{
	text.setPosition(button.getPosition().x + x, button.getPosition().y + y);
}

