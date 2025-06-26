#include "Application.h"
#include "Input.h"

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
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		mPlayer.Render(mHdc);
		mPlayer2.Render2(mHdc);
	}
}