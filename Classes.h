#pragma once
#include <string>
#include <vector>

namespace School {

	class Lecture
	{
	public:
		inline Lecture(std::string name, int id) { Name = name; Identifier = id; }

	public:
		std::string Name;
		int Identifier;
	};

	class Student
	{
	public:
		inline Student(std::string name, std::string lastName, std::string id,
			std::vector<Lecture*> lectures, std::vector<float> grades)
		{
			if (id.length() != 8)
			{
				throw std::exception("Invalid student id");
			}
			Name = name;
			LastName = lastName;
			Id = id;
			Lectures = lectures;
			Grades = grades;
		}
		// fields
	public:
		std::string Name;
		std::string LastName;
		std::string Id;
		std::vector<Lecture*> Lectures;
		std::vector<float> Grades;

		// functions
	public:
		inline float getAverageGrade()
		{
			float sum = 0;
			for (size_t i = 0; i < Grades.size(); i++)
			{
				sum += Grades[i];
			}
			return sum / Grades.size();
		}

		inline void addLecture(Lecture* lecture)
		{
			Lectures.push_back(lecture);
		}

		inline void addGrade(float grade)
		{
			Grades.push_back(grade);
		}
		inline std::string getLectureList()
		{
			if (Lectures.size() != Grades.size())
				throw std::exception("lectures and grades not same size!");

			std::string output;
			for (size_t i = 0; i < Grades.size(); i++)
			{
				output += "Name: " + Lectures[i]->Name + "  Grade: " + std::to_string(Grades[i]) + "\n";
			}

			return output;
		}
	};

	class School
	{
	public:
		inline School(std::string name, std::vector<Student> students)
		{
			Name = name;
			Students = students;
		}
	public:
		std::string Name;
		std::vector<Student> Students;		
	};

	class University
	{
	public:
		inline University(std::string name, std::vector<School> schools)
		{
			Name = name;
			Schools = schools;
		}
	public:
		std::string Name;
		std::vector<School> Schools;
	};
}