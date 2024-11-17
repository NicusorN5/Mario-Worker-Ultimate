#include "MusicW.hpp"
#include "..\GameResourceLoadException.hpp"

MusicW::MusicW(const std::filesystem::path& path) :
	_music(LoadMusicStream(path.string().c_str()))
{
	if(_music.ctxData == nullptr) throw GameResourceLoadException(path);
}

MusicW& MusicW::operator=(MusicW&& music) noexcept
{
	//Skip m = std::move(m);
	if(_music.ctxData == music._music.ctxData) return *this;
	if(_music.stream.buffer == music._music.stream.buffer) return *this;

	if(IsValid())
	{
		UnloadMusicStream(_music);
	}

	_music = music._music;
	return *this;
}

MusicW::operator const Music() const noexcept
{
	return _music;
}

const Music* MusicW::operator&() const noexcept
{
	return &_music;
}

const Music MusicW::GetUnderlyingMusic() const noexcept
{
	return _music;
}

bool MusicW::IsValid() const noexcept
{
	return _music.ctxData != nullptr || _music.stream.buffer != nullptr;
}

MusicW::~MusicW()
{
	if(IsValid())
	{
		UnloadMusicStream(_music);
	}
}