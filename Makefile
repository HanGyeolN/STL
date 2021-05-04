.PHONY: all clean fclean re

_END		=	\033[0;0m
_RED		=	\033[0;31m
_GREEN		=	\033[0;32m

NAME = container_test

CXX = clang++

CXXFLAGS = -std=c++98 -I ${INC_DIR} -g -fsanitize=address

INC_DIR = ./srcs

SRCS = $(wildcard ./srcs/*.cpp)

OBJS = $(patsubst %.cpp, %.o, ${SRCS})

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) $(LIBS) -o $(NAME) 

%.o : %.cpp
	$(CXX) -o $@ -c $^ $(CXXFLAGS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

bonus : 

re : fclean all
