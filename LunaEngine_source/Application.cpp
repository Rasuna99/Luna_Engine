#include "Application.h"
#include "Input.h"
#include "LuTime.h"

namespace Luna
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
	{

	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND Hwnd)
	{
		mHwnd = Hwnd;
		mHdc = GetDC(Hwnd);

		mPlayer.SetPosition(0, 0);
		mPlayer2.SetPosition(0, 0);

		Input::Initialize();
		Time::Initialize();
	}
	
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		mPlayer.Update();
		mPlayer2.Update2();
		Input::Update();
		Time::Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		Time::Render(mHdc);
		mPlayer.Render(mHdc);
		mPlayer2.Render2(mHdc);
	}
}