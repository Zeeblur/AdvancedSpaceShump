#include "GameObject.h"
#include "StateManager.h"

GameObject::~GameObject(){}

void GameObject::death(bool stop)
{
	if (stop)
	{
		//end game
		std::cout << "DIED" << std::endl;
        return;
	}

    this->visible = false;
    this->_parentState->AddScore(15);

	// change sprite here.
	// if player
	// if swan
	// if swan2
}

void GameObject::Update(const float& dt)
{
    if (!noD && !enemy)
        return;

    auto sprite = dynamic_cast<SpriteObject*>(this);
    auto myView = _parentState->mainWindow->getView();
    // check for objects out of scope
    auto point = sprite->sprite.getPosition();
    auto rect = _parentState->mainWindow->getViewport(myView).contains(point.x, point.y);
    if (!rect)
    {
        this->visible = false;

        if (enemy)
        {
            _parentState->AddScore(1);
        }

    }

}

void GameObject::setPosition(const Vector2f &newPos)
{
	position = newPos;
	dirty = true;
}

Vector2f GameObject::getPosition()
{
    auto sprite = dynamic_cast<SpriteObject*>(this);
    return sprite->sprite.getPosition();
}

void GameObject::Fire()
{
    moveSpeed = Vector2f(0.0f, 10.0f * moveScale);
    noD = true;
}

void GameObject::addImpulse(const Vector2f &direction)
{
	moveSpeed += Vector2f(direction.x * acceleration.x, direction.y * acceleration.y);
	moveReq = true;

	// limit movement
	if (moveSpeed.x > maxSpeed) moveSpeed.x = maxSpeed;
	if (moveSpeed.x < -maxSpeed) moveSpeed.x = -maxSpeed;
	if (moveSpeed.y > maxSpeed) moveSpeed.y = maxSpeed;
	if (moveSpeed.y < -maxSpeed) moveSpeed.y = -maxSpeed;
}

bool GameObject::CheckCollision(GameObject *other)
{
	// check collision with this object

	auto play = dynamic_cast<SpriteObject*>(this);
	auto enemy = dynamic_cast<SpriteObject*>(other);

	return play->sprite.getGlobalBounds().intersects(enemy->sprite.getGlobalBounds());
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
	// debug draw bounding boxes.
	//auto rect = RectangleShape(Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
	//rect.setPosition(sprite.getPosition());
	//window.draw(rect);

    if (visible)
        window.draw(sprite);
}

void SpriteObject::Update(const float& dt)
{
    if (dirty)
    {
        sprite.setPosition(position);
        dirty = false;
    }
    GameObject::Update(dt);

	// if no input request. Decelerate
	if (!moveReq && !noD)
	{
		//std::cout << moveSpeed.x << ", " << moveSpeed.y << std::endl;
		// lateral movement
		if (moveSpeed.x < 0) moveSpeed.x += deceleration.x;
		if (moveSpeed.x > 0) moveSpeed.x -= deceleration.x;

		// if speed within epsilon of zero. Reset to zero
		if (moveSpeed.x > 0 && moveSpeed.x <  deceleration.x) moveSpeed.x = 0;
		if (moveSpeed.x < 0 && moveSpeed.x > -deceleration.x) moveSpeed.x = 0;

		// vertical movement
		if (moveSpeed.y < 0) moveSpeed.y += deceleration.y;
		if (moveSpeed.y > 0) moveSpeed.y -= deceleration.y;

		// if speed within epsilon of zero. Reset to zero
		if (moveSpeed.y > 0 && moveSpeed.y < deceleration.y) moveSpeed.y = 0;
		if (moveSpeed.y < 0 && moveSpeed.y > -deceleration.y) moveSpeed.y = 0;
	}

	// update pos
	sprite.move(moveSpeed*dt);
	boundingBox = FloatRect(sprite.getLocalBounds());
	moveReq = false;
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


