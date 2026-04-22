#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
	{
		std::cout << "\nTESTING FORM CONSTRUCTORS AND DEFAULT VALUES:" << std::endl;
		Form form;
		std::cout << form;
	}
	{
		std::cout	<< "\nTESTING INVALID CONSTRUCTOR PARAMETERS:" << std::endl
					<< "Too high sign grade: ";
		try
		{
			Form form("Top Secret", 0, 1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Too high execute grade: ";
		try
		{
			Form form("Top Secret", 1, 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Too low sign grade: ";
		try
		{
			Form form("Top Secret", 151, 1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Too low execute grade: ";
		try
		{
			Form form("Top Secret", 1, 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nCREATING EARL AND HIS FORM:" << std::endl;
		Bureaucrat earl("Earl", 51);
		Form form("his own death warrant", 50, 100);
		std::cout << '\n' << earl << '\n';
		std::cout << '\n' << form << '\n';
		std::cout << "\nTESTING FORM SIGNING WITH INSUFFICIENT GRADE:" << std::endl;
		earl.signForm(form);
		std::cout << "\nTESTING SUCCESSFUL FORM SIGNING (AFTER INCREMENTING GRADE):" << std::endl;
		earl.incrementGrade();
		earl.signForm(form);
		std::cout << '\n' << form;
		std::cout << "\nTESTING DOUBLE-SIGNING A FORM:" << std::endl;
		earl.signForm(form);
		std::cout << std::endl;
	}
}
