#include "Classes.h"
#include "Points.h"
#include "Files.h"
#include <iostream>
#include "Hydro.h"

int main()
{
	School::Lecture* lecture1 = new School::Lecture("Cpp", 0);
	std::vector<School::Lecture*> lectures{};
	lectures.push_back(lecture1);

	std::vector<float> grades;
	grades.push_back(10.0f);
	try
	{
		School::Student* giannis = new School::Student("Giannis", "Mpoygas", "08122053", lectures, grades);

		School::Lecture* lecture2 = new School::Lecture("C#", 1);
		giannis->addLecture(lecture2);
		giannis->addGrade(8.0f);

		std::cout << giannis->getLectureList();
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}

	Core::Point2d p1 = Core::Point2d(1, 1);
	Core::Point2d p2 = Core::Point2d(2, 2);

	Core::Vector2d v1 = p1 - p2;
	Core::Vector2d v2 = p2 - p1;

	v1.Normalize();

	// example with base class
	std::vector<Core::BaseClass*> objs;
	objs.push_back(&v1);
	objs.push_back(&v2);
	objs.push_back(&p1);
	objs.push_back(&p2);

	std::string content;
	for (size_t i = 0; i < objs.size(); i++)
	{
		//std::cout << objs[i]->toString() << std::endl;
		content += objs[i]->toStringOnlyValues() + "\n";
	}

	//std::string path = "C:\\Users\\orestis\\Desktop\\cpp.txt";

	//if (Core::ReadFile(path, content)) {
	//	std::cout << content;
	//}

	std::string outPath = "C:\\Users\\orestis\\Desktop\\cpp2.txt";
	//if (Core::WriteFile(outPath, content))
	//{
	//	std::cout << "Successfully wrote to " + outPath;
	//}
	//std::vector<Core::Vector2d> vecs;
	//Core::ReadVector2dArrayFromFile(outPath, vecs);

	std::vector<Core::Point2d> points;
	std::vector<Core::Color> colors;

	Core::ReadPointsAndColorsFromFile(outPath, points, colors);

	double Length = 100; //units
	double Diameter = 5;
	int sectionCount = 31;
	std::vector<Hydro::Section> Sections;
	// circle : x2 + y2 = r2 = (d/2)2 = d2/4
	// y = sqrt(d2/4 - x2)


	// construct sections
	double dx = Length / (sectionCount - 1);

	std::vector<Hydro::Section> newSections;
	Core::ReadSectionsFile(outPath, newSections);
	Hydro::Ship ship(dx, newSections);
	double volume = ship.Volume();

	double expected = 3.14159 * Diameter * Diameter / 4 * Length;
	std::cout << "Volume is: " << volume << " expected is: " << expected << "\nError: " << abs(expected - volume) / expected << "%";

	// save sections to file
	//Core::WriteFile(outPath, ship.toString());
}
