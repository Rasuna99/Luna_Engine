#pragma once
#include "Entity.h"
#include "Component.h"
#include "Texture.h"

namespace Luna
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetScale(math::Vector2 scale) { mScale = scale; }

	private:
		graphics::Texture* mTexture;
		math::Vector2 mScale;
	};
}
