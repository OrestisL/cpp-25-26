#pragma once
#include <vector>
#include "Points.h"
namespace Hydro
{
	class Section
	{
	public:
		inline Section(double x, double dx, std::vector<Core::Point2d> points)
		{
			m_x = x;
			m_dx = dx;
			m_points = points;
		}
	private:
		double m_x, m_dx;
		std::vector<Core::Point2d> m_points;

	public:
		inline double DX() { return m_dx; }
		inline std::vector<Core::Point2d> Points()
		{
			return m_points;
		}
		double Area()
		{
			double sum = 1 * m_points[0].Y() + 1 * m_points[m_points.size() - 1].Y(); // 1 is simpson

			for (size_t i = 1; i < m_points.size() - 1; i++)
			{
				if (i % 2 == 0)
				{
					sum += 2 * m_points[i].Y();
				}
				else
				{
					sum += 4 * m_points[i].Y();
				}
			}

			return sum * m_dx / 3;
		}
	};


	class Ship
	{
	public:
		inline Ship(double dx, std::vector<Section> sections)
		{
			m_dx = dx;
			m_sections = sections;
		}
	private:
		double m_dx;
		std::vector<Section> m_sections;

	public:
		inline double Volume()
		{
			double volume = 0;
			for (size_t i = 0; i < m_sections.size(); i++)
			{
				double sectionX = i * m_dx;
				
				if (i == 0 || i == m_sections.size() - 1)
					volume += m_sections[i].Area();
				else if (i % 2 == 0)
					volume += 4 * m_sections[i].Area();
				else
					volume += 2 * m_sections[i].Area();
			}

			return 2 * m_dx / 3 * volume;
		}

		std::string toString()
		{
			std::string header;
			std::string pointsList;
			std::string output;
			for (size_t i = 0; i < m_sections.size(); i++)
			{
				header = "#Section " + std::to_string(i) + " " + std::to_string(m_sections[i].DX());
				auto points = m_sections[i].Points();
				for (size_t j = 0; j < points.size(); j++)
				{
					pointsList += points[j].toStringOnlyValues() + "\n";
				}
				output += header + "\n";
				output += pointsList + "\n";
				pointsList = "";
			}

			return output;
		}
	};

}