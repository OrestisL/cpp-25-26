#pragma once
#include "Hydro.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

namespace Core {
	inline bool ReadFile(const std::string& path, std::string& content)
	{
		std::ifstream file(path, std::ios::in);

		if (!file.is_open())
			return false;

		std::string line;

		while (std::getline(file, line))
		{
			content += line + "\n";
		}

		file.close();

		return true;
	}

	inline bool WriteFile(const std::string& path, const std::string& content)
	{
		std::ofstream file(path, std::ios::out);

		if (!file.is_open())
			return false;

		file.write(content.c_str(), content.size());
		file.close();

		return true;
	}

	inline bool ReadVector2dArrayFromFile(const std::string& path, std::vector<Core::Vector2d>& vectors)
	{
		std::ifstream file(path, std::ios::in);

		if (!file.is_open())
			return false;

		std::string line;

		while (std::getline(file, line))
		{
			if (line.size() == 0)
				continue;

			std::istringstream iss(line);
			std::string xIn, yIn;

			// read from stream into variables
			iss >> xIn >> yIn;

			double x = std::stod(xIn);
			double y = std::stod(yIn);
			vectors.push_back(Vector2d(x, y));
		}

		file.close();

		return true;
	}

	inline bool ReadPointsAndColorsFromFile(const std::string& path, std::vector<Core::Point2d>& points,
		std::vector<Core::Color>& colors)
	{
		std::ifstream file(path, std::ios::in);

		if (!file.is_open())
			return false;

		std::string line;
		std::string header;
		while (std::getline(file, line))
		{
			if (line.size() == 0)
				continue;

			if (line == "#Points" || line == "#Colors")
			{
				header = line;
				continue;
			}

			std::istringstream iss(line);

			if (header == "#Colors")
			{
				std::string rIn, gIn, bIn;
				// read from stream into variables
				iss >> rIn >> gIn >> bIn;

				double r = std::stod(rIn);
				double g = std::stod(gIn);
				double b = std::stod(bIn);

				colors.push_back(Core::Color(r, g, b));
			}
			else if (header == "#Points")
			{
				std::string xIn, yIn;

				iss >> xIn >> yIn;

				double x = std::stod(xIn);
				double y = std::stod(yIn);
				points.push_back(Core::Point2d(x, y));
			}

		}

		file.close();

		return true;
	}

	bool ReadSectionsFile(const std::string& path, std::vector<Hydro::Section>& sections)
	{
		std::ifstream file(path, std::ios::in);

		if (!file.is_open())
			return false;

		std::string line;
		while (std::getline(file, line))
		{
			if (line.find("#Section") != std::string::npos)
			{
				std::istringstream iss(line);
				std::string sectionString;
				std::string id, dx;
				iss >> sectionString >> id >> dx;

				// read specific id only
				//if (std::stoi(id) != inputId)
				//	continue;

				// read all points
				std::vector<Core::Point2d> points;
				while (std::getline(file, line))
				{
					if (line.size() == 0 || line.find("#Section") != std::string::npos)
						break;

					std::istringstream iss1(line);
					std::string xIn, yIn;
					iss1 >> xIn >> yIn;
					double x = stod(xIn);
					double y = stod(yIn);

					points.push_back(Core::Point2d(x, y));
				}
				sections.push_back(Hydro::Section(stod(id), stod(dx), points));
			}
		}

		return true;
	}
}