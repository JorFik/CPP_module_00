CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook
_SRC = main.cpp PhoneBook.cpp Contact.cpp
SRC = $(patsubst %, src/%, $(_SRC))
OBJ = $(SRC:src/%.cpp=bin/%.o)
INCLUDES = -I./include

all: $(NAME)

bin:
	@mkdir bin

bin/%.o: src/%.cpp | bin
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re