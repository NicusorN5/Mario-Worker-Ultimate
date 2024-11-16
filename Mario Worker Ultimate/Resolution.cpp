#include "Resolution.hpp"

namespace Game
{
	namespace Resolution
	{
		unsigned X;
		unsigned Y;

		Vector2 Vec()
		{
			return Vector2(
				static_cast<float>(X),
				static_cast<float>(Y)
			);
		}
		float FltX()
		{
			return X;
		}
		float FltY()
		{
			return Y;
		}
	}

	Rectangle ScreenRec(Rectangle norm)
	{
		return
		{
			norm.x * Resolution::X,
			norm.y * Resolution::Y,
			norm.width * Resolution::X,
			norm.height * Resolution::Y
		};
	}

	Vector2 ScreenRec(Vector2 norm)
	{
		return
		{
			norm.x * Resolution::X,
			norm.y * Resolution::Y
		};
	}
}