#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "assert.h"
#include "Renderer.h"
#include "Animation.h"

namespace Luna
{
	SpriteRenderer::SpriteRenderer()
		: mScale(Vector2::one)
		, mTexture(nullptr)
		, Component(enums::eComponentType::SpriteRenderer)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();
		pos = renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y, mTexture->GetWidth() * mScale.x * scale.x, mTexture->GetHeight() * mScale.y * scale.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(), RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(Gdiplus::Color(225, 225, 225), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage(), Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mScale.x * scale.x, mTexture->GetHeight()* mScale.y * scale.y)
				, 0, 0, mTexture->GetWidth(), mTexture->GetHeight(), Gdiplus::UnitPixel, nullptr);
		}
		//Gdiplus::Graphics graphics(hdc);
		//graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}
	
}