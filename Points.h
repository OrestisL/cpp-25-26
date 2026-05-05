#pragma once
#include <math.h>

namespace Core
{
	class BaseClass
	{
	public:
		virtual std::string toString() { return "Hello!"; }
	};

	class Color : public BaseClass
	{
	public:
		inline Color(float r, float g, float b)
		{
			m_r = r;
			m_g = g;
			m_b = b;
		}
	private:
		float m_r, m_g, m_b;

	public:
		inline float R() const { return m_r; }
		inline float G() const { return m_g; }
		inline float B() const { return m_b; }
		std::string toString() override {
			return "R: " + std::to_string(m_r) + " G: " + std::to_string(m_g) +
				" B: " + std::to_string(m_b);
		}
	};

	class Vector2d : public BaseClass
	{
	public:
		inline Vector2d(double x, double y)
		{
			m_x = x;
			m_y = y;
			m_length = sqrt(x * x + y * y);
			m_angle = atan2(y, x);
		}
	private:
		double m_x, m_y, m_angle, m_length;

	public:
		inline double X() const { return m_x; }
		inline double Y() const { return m_y; }
		inline double AngleDeg() const { return m_angle * 180 / 3.14159; }
		inline double AngleRad() const { return m_angle; }
		inline double Length() const { return m_length; }
		inline double Dot(const Vector2d& other) { return (*this) * other; }
		inline void Normalize()
		{
			if (m_length == 0) return;

			m_x /= m_length;
			m_y /= m_length;

			m_length = 1;
		}
		// add cross
		std::string toString() override
		{
			return "X: " + std::to_string(m_x) + " Y: " + std::to_string(m_y);
		}
	public:
		double operator*(const Vector2d& other)
		{
			return m_x * other.X() + m_y * other.Y();
		}
	};

	class Point2d : public BaseClass
	{
	public:
		inline Point2d(double x, double y) { m_x = x; m_y = y; }

	private:
		double m_x, m_y;

	public:
		inline double X() const { return m_x; }
		inline double Y() const { return m_y; }
	public:
		Vector2d operator- (const Point2d& other)
		{
			return Vector2d(m_x - other.X(), m_y - other.Y());
		}
		std::string toString() override
		{
			return "X: " + std::to_string(m_x) + " Y: " + std::to_string(m_y);
		}
	};
}