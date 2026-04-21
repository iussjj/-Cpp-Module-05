#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	{
		std::cout << "TESTING DEFAULT CONSTRUCTOR AND DESTRUCTOR:" << std::endl;
		Bureaucrat anon; //creating stack-allocated default bureaucrat
		std::cout << anon << std::endl; //output bureaucrat
	}
	{
		std::cout << "\nTESTING PARAMETRIZED CONSTRUCTOR:" << std::endl;
		Bureaucrat steve("Steve", 1);
		std::cout << steve << std::endl;
		Bureaucrat earl("Earl", 150);
		std::cout << earl << std::endl;
		std::cout << "\nTESTING COPY CONSTRUCTOR (COPY FROM STEVE):" << std::endl;
		Bureaucrat copy(steve);
		std::cout << copy << std::endl;
		std::cout << "\nTESTING COPY ASSIGNMENT (INCOMPLETE COPY FROM EARL):" << std::endl;
		copy = earl;
		std::cout << copy << std::endl;
		std::cout << "\nTESTING INVALID INCREMENT/DECREMENT:" << std::endl;
		try
		{
			steve.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Invalid increment for Steve: " << e.what() << std::endl;
		}
		try
		{
			earl.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Invalid decrement for Earl: " << e.what() << std::endl;
		}

		std::cout << "\nTESTING VALID GRADE DECREMENT/INCREMENT:" << std::endl;
		std::cout << "Before decrement/increment:" << std::endl;
		std::cout << steve << std::endl;
		std::cout << earl << std::endl;
		earl.incrementGrade();
		steve.decrementGrade();
		std::cout << "\nAfter decrement/increment:" << std::endl;
		std::cout << steve << std::endl;
		std::cout << earl << std::endl;
	}
	{
		std::cout << "\nTESTING INVALID CONSTRUCTOR PARAMETERS:" << std::endl;
		{
			try
			{
				Bureaucrat nope("Not happening", 0);
			}
			catch(const std::exception& e)
			{
				std::cerr << "Invalid constructor parameter: " << e.what() << std::endl;
			}
		}
		{
			try
			{
				Bureaucrat nope("Not happening", 151);
			}
			catch(const std::exception& e)
			{
				std::cerr << "Invalid constructor parameter: " << e.what() << std::endl;
			}
		}
	}
}
