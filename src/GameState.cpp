#include "GameState.h"
#include "GameObject.h"
#include "StateManager.h"

void GameState::AddScore(int val)
{
    playerScore += val;
}

void GameState::Render(RenderWindow &window) const
{
	//std::cout << "render gs.cpp" << std::endl;
	// for each game object. Render
	for(GameObject* go : stateObjects)
	{
		go->Render(window);
	}
}

void GameState::AddObject(const GameObject &go)
{
	//stateObjects.push_back(&go);
}

void GameState::Click(utils::stateType &val) 
{
	parent->Click(val);
}

TextObject* GameState::CreateText(String s, float textSize, Vector2f displacement)
{
	Text testText;

	testText.setString(s);
	testText.setFont(*mainFont);
	testText.setCharacterSize(textSize);
	testText.setStyle(Text::Bold);
	testText.setColor(Color::White);

	// set origin to middle of object
	testText.setOrigin(Vector2f(testText.getLocalBounds().width / 2.f, testText.getLocalBounds().height / 2.f));

	//// set pos to middle of screen then add displacement

	testText.setPosition((mainView->getSize() / 2.0f) + displacement);

	return new TextObject(testText, *this);
}

SpriteObject* GameState::CreateSprite(const Texture& texture, Vector2f scale, Vector2f pos, IntRect sourceRect)
{
	Sprite sprite;

	// set image sprite
	sprite.setTexture(texture);

	sprite.setScale(scale);

    sprite.setPosition(pos);

	return new SpriteObject(sprite, *this);
}