#include "GameObject.h"
#include "StateManager.h"

GameObject::~GameObject(){}

void GameObject::setPosition(const Vector2f &newPos)
{
	position = newPos;
	dirty = true;
}

void GameObject::addPos(const Vector2f &newPos)
{
	movement = newPos;
	dirty = true;
}


// Sprite object

SpriteObject::SpriteObject(Sprite &spr, GameState& parent) : sprite(spr)
{
	boundingBox = FloatRect(sprite.getLocalBounds());
	position = Vector2f(sprite.getPosition());
	_parentState = &parent;
}

void SpriteObject::Render(RenderWindow &window)
{
	//std::cout << "spritetyy" << std::endl;
	window.draw(sprite);
}

void SpriteObject::Update(const float& dt)
{
	
	if (!dirty)
		return;


	sprite.move(movement*300.0f*dt);
	

	boundingBox = FloatRect(sprite.getLocalBounds());

	dirty = false;
}


// Text object

TextObject::TextObject(const Text &txt, GameState& parent) : text(txt)
{
	boundingBox = FloatRect(text.getLocalBounds());
	position = Vector2f(text.getPosition()); 
	_parentState = &parent;
}

void TextObject::Render(RenderWindow &window)
{
	//std::cout << "texty" << std::endl;
	window.draw(text);
}

void TextObject::Update(const float& dt)
{
	if (!dirty)
		return;

	text.setPosition(position);
	
	dirty = false;
}


// InteractiveObject - base style can customize later

InteractiveObject::InteractiveObject(GameState& parent, TextObject* textObj, SpriteObject* spriteObj) : text(textObj), sprite(spriteObj)
{
	float shapeWidth = 100.0f;
	float shapeHeight = 50.0f;

	// fit size of shape to text.
	shapeWidth = text->boundingBox.width + (text->boundingBox.width * 0.3f);
	shapeHeight = text->boundingBox.height * 2.0f;

	backshape = RectangleShape(Vector2f(shapeWidth, shapeHeight));
	backshape.setOutlineColor(Color::White);
	backshape.setOutlineThickness(2.0f);

	// centre text to shape
	Vector2f buttonPos = (text->text.getPosition() - Vector2f(shapeWidth / 2.0f, shapeHeight / 2.0f));
	backshape.setPosition(buttonPos);

	// set bounding box
	boundingBox = backshape.getGlobalBounds();// FloatRect(backshape.getPosition().x, backshape.getPosition().y, shapeWidth, shapeHeight);

	//auto a = 
	

	// ghet parent
	_parentState = &parent;
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
	// Clicked this button type.
	_parentState->Click(buttonValue);
}

void InteractiveObject::HoverGraphics(const bool &val)
{
	if (val)
	{


		auto a = Mouse::getPosition(*_parentState->mainWindow);

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

void InteractiveObject::Update(const float& dt)
{

	if (text != nullptr)
		text->Update(dt);

	if (sprite != nullptr)
		sprite->Update(dt);


	// ensure mouse positon is relative to the viewport
	auto mousePos = _parentState->mainWindow->mapPixelToCoords(Mouse::getPosition(*_parentState->mainWindow));

	// update each object within interactive
	HoverGraphics(boundingBox.contains(Vector2f(mousePos)));


}


