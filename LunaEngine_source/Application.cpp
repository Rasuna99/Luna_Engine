#include "Application.h"
#include "Input.h"
#include "LuTime.h"

namespace Luna
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBuffer(NULL)
	{

	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND Hwnd, UINT width, UINT height)
	{
		mHwnd = Hwnd;
		mHdc = GetDC(Hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		// 윈도우 해상도에 맞는 백버퍼 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);
		// 백버퍼를 가르킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);
		
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
		Rectangle(mBackHdc, -1, -1, 1601, 901);

		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);
		mPlayer2.Render2(mBackHdc);

		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}