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
	shapeHeight = text->boundingBox.height * 2.0f;	//boundingBox.left = backshape.getPosition().x;
	//boundingBox.top = backshape.getPosition().y;


	backshape = RectangleShape(Vector2f(shapeWidth, shapeHeight));
	backshape.setOutlineColor(Color::White);
	backshape.setOutlineThickness(2.0f);
	backshape.setPosition(Vector2f(200, 200));

	// centre text to shape
	text->setPosition(Vector2f(200, 200) +Vector2f(shapeWidth / 2.0f, shapeHeight / 2.0f));

	// set bounding box
	boundingBox = FloatRect(backshape.getPosition().x, backshape.getPosition().y, shapeWidth, shapeHeight);

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

void InteractiveObject::Click()
{

}

void InteractiveObject::HoverGraphics(const bool &val)
{
	if (val)
	{
		// if hovering alter style
		backshape.setFillColor(Color::White);

		text->text.setColor(Color::Black);

		if (Mouse::isButtonPressed(Mouse::Left) && !previousMouseState)
		{
			std::cout << "clicked button" << std::endl;
			Click();
		}
	}
	else
	{
		backshape.setFillColor(Color::Transparent);
		text->text.setColor(Color::White);
	}

	previousMouseState = Mouse::isButtonPressed(Mouse::Left);
}


void InteractiveObject::Update()
{
	// update each object within interactive
	HoverGraphics(boundingBox.contains(Vector2f(Mouse::getPosition())));

	if (text != nullptr)
		text->Update();

	if (sprite != nullptr)
		sprite->Update();
}

