#include "GameState.h"

//GameObject::~GameObject(){}

// Sprite object

SpriteObject::SpriteObject(Sprite *spr) : sprite(std::unique_ptr<Sprite>(spr))
{
	boundingBox = FloatRect(sprite->getLocalBounds());
	position = Vector2f(boundingBox.left, boundingBox.top);
}

void SpriteObject::Render(RenderWindow &window) const
{
	window.draw(*sprite);
}



// Text object

TextObject::TextObject(const Text &txt) : text(txt)
{
	boundingBox = FloatRect(text.getLocalBounds());
	position = Vector2f(boundingBox.left, boundingBox.top);
}

TextObject::TextObject(const TextObject& other)
{

}


void TextObject::Render(RenderWindow &window) const
{
	window.draw(text);
}