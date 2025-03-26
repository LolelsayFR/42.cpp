NAME			=	megaphone

SRC				=	megaphone.cpp\

CFLAGS			=	-Wall -Werror -Wextra -std=c++98

all:	hello $(NAME)

hello:
	@echo "\e[48;2;100;0;100;1m Welcome to "$(NAME)" Makefile !\e[0m\n"

$(NAME): ${SRC}
	@echo "\e[48;2;0;155;0;1m Compile "$(NAME)" \e[0m\n"
	g++ ${SRC} ${CFLAGS} -o $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

clean: hello
	@echo "\e[48;2;155;100;0;1m Clean "$(NAME)" dependencies \e[0m\n"
	@echo "No dependencies."
	@echo "\n\e[48;2;0;0;155;1m Done \e[0m\n"

fclean: hello clean
	@echo "\e[48;2;155;100;0;1m Uninstall "$(NAME)" \e[0m\n"
	$(RM) $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

re:	fclean all

.PHONY: all clean fclean re
