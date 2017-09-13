#include "GameObject.h"

GameObject::~GameObject(){}

// Sprite object

SpriteObject::SpriteObject(const Sprite &spr) : sprite(spr)
{
	boundingBox = FloatRect(sprite.getLocalBounds());
	position = Vector2f(boundingBox.left, boundingBox.top);
}

void SpriteObject::Render(RenderWindow &window)
{
	//std::cout << "spritetyy" << std::endl;
	window.draw(sprite);
}



// Text object

TextObject::TextObject(const Text &txt) : text(txt)
{
	boundingBox = FloatRect(text.getLocalBounds());
	position = Vector2f(text.getPosition()); 
}

void TextObject::Render(RenderWindow &window)
{
	//std::cout << "texty" << std::endl;
	window.draw(text);
}

void TextObject::Update()
{
	if (!dirty)
		return;

	text.setPosition(position);
	
	dirty = false;
}


// InteractiveObject - base style can customize later

void GameObject::setPosition(const Vector2f &newPos)
{
	position = newPos;
	dirty = true;
}

InteractiveObject::InteractiveObject(TextObject* textObj, SpriteObject* spriteObj) : text(textObj), sprite(spriteObj)
{
	float shapeWidth = 100.0f;
	float shapeHeight = 50.0f;

	// fit size of shape to text.
	shapeWidth = text->boundingBox.width * 2.0f;
	shapeHeight = text->boundingBox.height * 2.0f;


	backshape = RectangleShape(Vector2f(shapeWidth, shapeHeight));
	backshape.setFillColor(sf::Color(100, 250, 50));

	backshape.setPosition(Vector2f(200, 200));

	// centre text to shape
	text->setPosition(Vector2f(200, 200) +Vector2f(shapeWidth / 2.0f, shapeHeight / 2.0f));


}

void InteractiveObject::Render(RenderWindow &window)
{
	// draw shape
	window.draw(backshape);

	// render text
	if (text != nullptr)
		text->Render(window);

	// render sprite
	if (sprite != nullptr)
		sprite->Render(window);

}

void InteractiveObject::Update()
{
	// update each object within interactive

	if (text != nullptr)
		text->Update();

	if (sprite != nullptr)
		sprite->Update();
}