NAME = Intern

CXX = c++
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98

INCLUDES = Bureaucrat.hpp AForm.hpp \
	  	   PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp
SRC = main.cpp Bureaucrat.cpp AForm.cpp \
	  PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf *_shrubbery

re: fclean all

.PHONY: all clean fclean re

