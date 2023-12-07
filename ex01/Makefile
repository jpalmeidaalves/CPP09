NAME	= RPN

CXX		= c++

CPPFLAGS	= -Wall -Werror -Wextra -std=c++98 -g

SRC		= main.cpp RPN.cpp

OBJ		= $(SRC:.cpp=.o)

RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJ) 
	$(CXX) $(CPPFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
re:	 fclean all

.PHONY:	all clean fclean re bonus
