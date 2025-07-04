#pragma once

namespace Luna::enums
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		End,
	};


	enum class eLayerTpye
	{
		None,
		BackGrond,
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