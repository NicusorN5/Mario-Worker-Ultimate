#pragma once
#include "../Libs.hpp"

class MusicW
{
	Music _music;
public:
	MusicW() = default;
	MusicW(const std::filesystem::path& path);

	MusicW(const MusicW&) = delete;
	MusicW(MusicW&&) = default;

	MusicW& operator=(const MusicW&) = delete;
	MusicW& operator=(MusicW&& music) noexcept;

	explicit operator const Music() const noexcept;
	const Music* operator&() const noexcept;

	const Music GetUnderlyingMusic() const noexcept;

	bool IsValid() const noexcept;

	~MusicW();
};