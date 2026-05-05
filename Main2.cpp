#include "Classes.h"
#include "Points.h"
#include <iostream>

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

	for (size_t i = 0; i < objs.size(); i++)
	{
		std::cout << objs[i]->toString() << std::endl;
	}
}
