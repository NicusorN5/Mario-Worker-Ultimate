#pragma once
#include "../Libs.hpp"

/// <summary>
/// RAII Raylib Texture2D wrapper.
/// </summary>
class Texture2DW
{
	Texture2D _texture;
public:
	Texture2DW() = default;
	Texture2DW(const std::filesystem::path& path);

	Texture2DW(const Texture2DW&) = delete;
	Texture2DW(Texture2DW&&) noexcept = default;

	Texture2DW& operator=(const Texture2DW&) = delete;
	Texture2DW& operator=(Texture2DW&& texture) noexcept;

	explicit operator const Texture2D() const noexcept;
	const Texture2D* operator&() const noexcept;
	const Texture2D GetUnderlyingTexture() const noexcept;

	bool IsValid() const noexcept;
	
	int Width() const noexcept;
	int Height() const noexcept;

	~Texture2DW();
};