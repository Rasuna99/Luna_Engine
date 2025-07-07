#pragma once

namespace Luna::enums
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		End,
	};


	enum class eLayerTpye
	{
		None,
		BackGround,
		Player,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}