








namespace Math
{
	const float Pi = 3.1415926535f;
	const float TwoPi = Pi * 2.0f;
	const float PiOverTwo = Pi / 2.0f;
	const float Epsilon = 0.001f;

	inline float toRadians(float degrees)
	{
		return degrees * Pi / 180.0f;
	}

	inline float toDegrees(float radians)
	{
		return radians * 180.0f / Pi;
	}

}


class Vector2
{
public:
	float x, y;

	Vector2()
		:x(0.0f)
		,y(0.0f)
	{ }

	explicit Vector2(float x, float y)
		:x(x)
		,y(y)
	{
	}

	friend Vector2 operator+(const Vector2& a, const  Vector2& b)
	{
		return Vector2(a.x + b.x, a.y + b.y);
	}

	friend Vector2 operator-(const Vector2& a, const  Vector2& b)
	{
		return Vector2(a.x - b.x, a.y - b.y);
	}

	friend Vector2 operator*(const Vector2& a, const  Vector2& b)
	{
		return Vector2(a.x * b.x, a.y * b.y);
	}

	friend Vector2 operator*=(const Vector2& a, float scalar)
	{
		return Vector2(a.x * scalar, a.y * scalar);
	}

	friend Vector2 operator*=(float scalar, const Vector2& a)
	{
		return Vector2(a.x * scalar, a.y * scalar);
	}

	Vector2& operator+=(const Vector2& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Vector2& operator-=(const Vector2& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	Vector2& operator*=(const int scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}
};