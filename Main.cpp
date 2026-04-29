#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "Namespace.h"

double getDoubleFromUser()
{
	try {
		std::string s = "";
		std::cout << "Input a number: ";
		std::cin >> s;

		double d = std::stod(s);

		return d;
	}
	catch (std::exception ex)
	{
		std::cout << ex.what();
	}
}

std::string getUserInput()
{
	std::string input = "";
	std::cout << "Choose rock, paper or scissors: ";
	std::cin >> input;

	return input;
}

int main(int argc, char* argv[])
{
	std::string play = "y";

	std::vector<std::string>
		choices{ "rock", "paper", "scissors" };

	std::default_random_engine gen;
	std::uniform_int_distribution<> 
		distr(0, choices.size() - 1);
	std::cout << test::Sum(3.2343423, 6.34567354);
	do 
	{
		std::string input = getUserInput();

		int rnd = distr(gen);
		std::string choice = choices[rnd];
		std::cout << "Computer chose :/" << choice << "/" << std::endl;
		if (choice == "rock")
		{
			if (input == "rock")
				std::cout << "Tie";
			else if (input == "scissors")
				std::cout << "You lose!";
			else if (input == "paper")
				std::cout << "You win!";
			else
			{
				std::cout << "invalid input\a";
			}
		}
		else if (choice == "paper") {
			if (input == "rock")
				std::cout << "You lose!";
			else if (input == "scissors")
				std::cout << "You win!";
			else if (input == "paper")
				std::cout << "Tie";
			else
			{
				std::cout << "invalid input\a";
			}
		}
		else if (choice == "scissors")
		{
			if (input == "rock")
				std::cout << "You win!";
			else if (input == "scissors")
				std::cout << "Tie";
			else if (input == "paper")
				std::cout << "You lose!";
			else
			{
				std::cout << "invalid input\a";
			}
		}

		std::cout << "\nplay again? (y/n) ";
		std::cin >> play;

	} while (play == "y" || play == "yes");
}


