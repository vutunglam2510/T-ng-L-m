#pragma once
#include "BaseObject.h"

class Sprite2D;
class Sprite3D;
class SpriteAnimation;

class Snake :
	public BaseObject
{
public:
	Snake();
	~Snake();

	void SetOnClick(void(*pBtClick)());
	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();

private:
	void (*m_pBtClick)();
	std::vector < std::shared_ptr<Snake>> m_listSnake;
	std::vector < std::shared_ptr<Sprite2D>> m_listSprite2D;
	std::vector < std::shared_ptr<SpriteAnimation>> m_listSpriteAnimations;
	int x, y;
};

