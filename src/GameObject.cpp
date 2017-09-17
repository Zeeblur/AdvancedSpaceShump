#include "GameObject.h"
#include "StateManager.h"

GameObject::~GameObject(){}

TextObject* GameState::CreateText(String s, Vector2f displacement)
{
	Text testText;

	testText.setString(s);
	testText.setFont(*mainFont);
	testText.setCharacterSize(20);
	testText.setStyle(Text::Bold);
	testText.setColor(Color::White);

	// set origin to middle of object
	testText.setOrigin(Vector2f(testText.getLocalBounds().width / 2.f, testText.getLocalBounds().height / 2.f));

	//// set pos to middle of screen then add displacement 

	testText.setPosition((mainView->getSize() / 2.0f) + displacement);

	return new TextObject(testText, *this);
}

SpriteObject* GameState::CreateSprite(const Texture& texture)
{
	Sprite sprite;
	//boundingBox.left = backshape.getPosition().x;
	//boundingBox.top = backshape.getPosition().y;

	// set image sprite
	sprite.setTexture(texture);
	sprite.setScale(Vector2f(2.f, 2.f));
	sprite.setOrigin(Vector2f(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f));
	sprite.setPosition(mainView->getSize() / 2.0f);

	return new SpriteObject(sprite, *this);
}

// Sprite object

SpriteObject::SpriteObject(Sprite &spr, GameState& parent) : sprite(spr)
{
	boundingBox = FloatRect(sprite.getLocalBounds());
	position = Vector2f(boundingBox.left, boundingBox.top);
	_parentState = &parent;
}

void SpriteObject::Render(RenderWindow &window)
{
	//std::cout << "spritetyy" << std::endl;
	window.draw(sprite);
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

InteractiveObject::InteractiveObject(GameState& parent, TextObject* textObj, SpriteObject* spriteObj) : text(textObj), sprite(spriteObj)
{
	float shapeWidth = 100.0f;
	float shapeHeight = 50.0f;

	// fit size of shape to text.
	shapeWidth = text->boundingBox.width * 2.0f;
	shapeHeight = text->boundingBox.height * 2.0f;

	backshape = RectangleShape(Vector2f(shapeWidth, shapeHeight));
	backshape.setOutlineColor(Color::White);
	backshape.setOutlineThickness(2.0f);
	backshape.setPosition(Vector2f(200, 200));

	// centre text to shape
	text->setPosition(Vector2f(200, 200) +Vector2f(shapeWidth / 2.0f, shapeHeight / 2.0f));

	// set bounding box
	boundingBox = FloatRect(backshape.getPosition().x, backshape.getPosition().y, shapeWidth, shapeHeight);

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


