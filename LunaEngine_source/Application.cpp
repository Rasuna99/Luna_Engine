#include "Application.h"


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
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		mPlayer.Render(mHdc);
	}
}