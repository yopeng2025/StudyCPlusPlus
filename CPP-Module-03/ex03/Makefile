NAME = FragTrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ScavTrap.cpp ClapTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGES) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CXX) $(CXXFLAGES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re