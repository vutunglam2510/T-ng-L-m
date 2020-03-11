#include "GSPlay.h"

#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "SpriteAnimation.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{

}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play");

	////BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);


	//back button
	texture = ResourceManagers::GetInstance()->GetTexture("button_back");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 100);
	button->SetSize(200, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		});
	m_listButton.push_back(button);

	//text game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_score = std::make_shared< Text>(shader, font, "score: 100", TEXT_COLOR::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	// Animation
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("coin2");
	std::shared_ptr<SpriteAnimation> obj = std::make_shared<SpriteAnimation>(model, shader, texture, 10, 0.1f);
	obj->Set2DPosition(240, 400);
	obj->SetSize(52, 52);
	m_listSpriteAnimations.push_back(obj);
}

void GSPlay::Exit()
{

}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{

}


void GSPlay::HandleEvents()
{

}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSPlay::Update(float deltaTime)
{
	for (auto obj : m_listSpriteAnimations)
	{
		obj->Update(deltaTime);
	}
}

void GSPlay::Draw()
{
	m_BackGround->Draw();

	for (auto obj : m_listSpriteAnimations)
	{
		obj->Draw();
	}
	m_score->Draw();
		for (auto it : m_listButton)
		{
			it->Draw();
		}

	
}

void GSPlay::SetNewPostionForBullet()
{
}