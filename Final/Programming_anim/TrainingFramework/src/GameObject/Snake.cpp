#include "Snake.h"

Snake::Snake()
{

}

Snake::~Snake()
{

}

void Snake::Draw()
{
	for (auto it : m_listSnake)
	{
		it->Draw();
	}
}
