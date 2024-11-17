#include "IButton.hpp"
#include "TransparentFont.hpp"


class Checkbox
{
	Texture2D _checkedTxd;
	Texture2D _uncheckedTxd;

	TransparentFont &_font;
	std::string _text;

	Vector2 _pos;
	Vector2 _scale;
	Vector2 _boxS;
	float _spacing;
public:
	Checkbox() = default;
	Checkbox(Checkbox&&) noexcept = default;

	Checkbox(
		const Texture2D &_cTxd,
		const Texture2D &_ucTxd,
		TransparentFont &f,
		const std::string& text,
		bool defState,
		const Vector2 &txtpos, 
		const Vector2 &boxScale,
		const Vector2 &scale,
		float spacing
	);

	Checkbox& operator=(Checkbox&&) noexcept = default;

	bool Checked;

	void Draw(float dt);
	void Update(MouseState* ms, float dt);

	std::function<void(bool)> OnStateChange = nullptr;
};