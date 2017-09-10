#include "GameState.h"

GameObject::~GameObject(){}

SpriteObject::SpriteObject(Sprite *spr) : sprite(std::unique_ptr<Sprite>(spr))
{
	boundingBox = std::unique_ptr<FloatRect>(&sprite->getLocalBounds());
	position = Vector2f(boundingBox->left, boundingBox->top);
}

void SpriteObject::Render(RenderWindow &window) const
{
	window.draw(*sprite);
}

void TextObject::Render(RenderWindow &window) const
{
	window.draw(*text);
}