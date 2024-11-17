#include "SoundW.hpp"
#include "..\GameResourceLoadException.hpp"

SoundW::SoundW(const std::filesystem::path& path)
{
	auto rawPath = path.string();

	if(path.extension().string() == "wav")
	{
		Wave w = LoadWave(rawPath.c_str());
		if(w.data == nullptr) throw GameResourceLoadException(path);
		_sound = LoadSoundFromWave(w);
	}
	else
	{
		Sound s = LoadSound(rawPath.c_str());
		if(s.stream.buffer == nullptr) throw GameResourceLoadException(path);
		_sound = s;
	}
}

SoundW& SoundW::operator=(SoundW&& sound) noexcept
{
	//skip a = std::move(a);
	if(_sound.stream.buffer == sound._sound.stream.buffer) return *this;

	if(IsValid())
	{
		UnloadSound(_sound);
	}

	_sound = sound._sound;
	return *this;
}

SoundW::operator const Sound() const noexcept
{
	return _sound;
}

const Sound* SoundW::operator&() const noexcept
{
	return &_sound;
}

const Sound SoundW::GetUnderlyingSound() const noexcept
{
	return _sound;
}

bool SoundW::IsValid() const noexcept
{
	return _sound.stream.buffer != nullptr;
}

SoundW::~SoundW()
{
	if(IsValid())
	{
		UnloadSound(_sound);
	}
}