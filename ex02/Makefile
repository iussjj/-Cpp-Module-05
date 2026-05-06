# Program name
NAME		= so_many_forms

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++20

# Source files and Object files
SRCS		=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS		=	$(SRCS:.cpp=.o)
HEADERS		=	Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
				RobotomyRequestForm.hpp PresidentialPardonForm.hpp

# Rules
all: $(NAME)

# Explicit rule so CXXFLAGS are guaranteed to apply
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re