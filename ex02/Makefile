CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = tests
SRC = Account.cpp tests.cpp
OBJ = $(SRC:%.cpp=bin/%.o)
INCLUDES = -I.

all: $(NAME)

bin:
	@mkdir bin

bin/%.o: %.cpp | bin
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re