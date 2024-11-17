#pragma once
#include "../Libs.hpp"

/// <summary>
/// RAII Raylib sound wrapper.
/// </summary>
class SoundW
{
	Sound _sound;
public:
	SoundW() = default;
	SoundW(const std::filesystem::path& path);

	SoundW(const SoundW&) = delete;
	SoundW(SoundW&&) noexcept = default;

	SoundW& operator=(const SoundW&) = delete;
	SoundW& operator=(SoundW&& sound) noexcept;

	explicit operator const Sound() const noexcept;
	const Sound* operator&() const noexcept;
	const Sound GetUnderlyingSound() const noexcept;

	bool IsValid() const noexcept;
	

	~SoundW();
};

