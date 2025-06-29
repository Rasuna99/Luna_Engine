#pragma once
#include "CommonInclude.h"

namespace Luna
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode KeyCode;
			eKeyState state;
			bool bPressed;
		};
		
		static void Initialize();
		static void Update();

		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }
		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down; }
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }

	private:
		static void CreateKeys();
	private:
		static std::vector<Key> mKeys;
	};
}

