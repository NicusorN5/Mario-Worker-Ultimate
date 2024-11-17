#include "Texture2DW.hpp"
#include "..\GameResourceLoadException.hpp"

Texture2DW::Texture2DW(const std::filesystem::path& path) :
	_texture(LoadTexture(path.string().c_str()))
{
	if(_texture.id == 0) throw GameResourceLoadException(path);
}

Texture2DW& Texture2DW::operator=(Texture2DW&& texture) noexcept
{
	if(_texture.id == texture._texture.id) return *this;

	if(IsValid())
	{
		UnloadTexture(_texture);
	}

	_texture = texture._texture;
	return *this;
}

Texture2DW::operator const Texture2D() const noexcept
{
	return _texture;
}

const Texture2D* Texture2DW::operator&() const noexcept
{
	return &_texture;
}

const Texture2D Texture2DW::GetUnderlyingTexture() const noexcept
{
	return _texture;
}

bool Texture2DW::IsValid() const noexcept
{
	return _texture.id != 0;
}

int Texture2DW::Width() const noexcept
{
	return _texture.width;
}

int Texture2DW::Height() const noexcept
{
	return _texture.height;
}

Texture2DW::~Texture2DW()
{
	if(IsValid())
	{
		UnloadTexture(_texture);
	}
}
