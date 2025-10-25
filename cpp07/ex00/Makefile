NAME			=	Whatever

SRC				=	main.cpp\

CFLAGS			=	-Wall -Werror -Wextra -std=c++98

CXX				=	c++

OBJ				= 	${SRC:.cpp=.o}

all:	hello $(NAME)

hello:
	@echo "\e[48;2;100;0;100;1m Welcome to "$(NAME)" Makefile !\e[0m\n"

$(NAME): $(OBJ)
	@echo "\e[48;2;0;155;0;1m Compile "$(NAME)" \e[0m\n"
	${CXX} $(OBJ) ${CFLAGS} -o $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

clean: hello
	@echo "\e[48;2;155;100;0;1m Clean "$(NAME)" dependencies \e[0m\n"
	$(RM) $(OBJ)
	@echo "\n\e[48;2;0;0;155;1m Done \e[0m\n"

fclean: hello clean
	@echo "\e[48;2;155;100;0;1m Uninstall "$(NAME)" \e[0m\n"
	$(RM) $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

%.o: %.cpp
	${CXX} ${CFLAGS} -c $< -o $@

re:	fclean all

.PHONY: all clean fclean re