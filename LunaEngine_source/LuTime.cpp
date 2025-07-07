#include "LuTime.h"

namespace Luna
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTime = 0.0f;

	void Luna::Time::Initialize()
	{
		// Cpu 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);

		// Cpu 현재 진동수
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTime = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTime;
		float fps = 1.0f / DeltaTime;

		//wchar_t str[50] = L"";
		//swprintf_s(str, 50, L"fps : %d", (int)fps);
		//int len = wcsnlen_s(str, 50);
		//
		//
		//TextOut(hdc, 0, 0, str, len);
	}

}