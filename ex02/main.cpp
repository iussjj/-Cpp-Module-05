#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int	main()
{
	Bureaucrat bureaucrat("Literally Jesus", 1);
	{
		std::cout << "\nTESTING SHRUBBERY FORM:" << std::endl;
		ShrubberyCreationForm shrub("bathroom");
		try
		{
			shrub.execute(bureaucrat);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		bureaucrat.signForm(shrub);
		shrub.execute(bureaucrat);
	}
	{
		std::cout << "\nTESTING ROBOTOMY FORM:" << std::endl;
		RobotomyRequestForm robo("Bender");
		bureaucrat.signForm(robo);
		for (int i = 0; i < 10; i++)
		{
			robo.execute(bureaucrat);
		}
	}
}
