NAME			=	brainz

SRC				=	main.cpp\
					zombieHorde.cpp\
					Zombie.cpp

CFLAGS			=	-Wall -Werror -Wextra -std=c++98

all:	hello $(NAME)

OBJ		= 	${SRC:.cpp=.o}

hello:
	@echo "\e[48;2;100;0;100;1m Welcome to "$(NAME)" Makefile !\e[0m\n"

d_info: hello
	@echo "\e[48;2;70;70;70;1m "$(NAME)" usage : \e[0m\n"
	@echo "./d_philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]\n"

$(NAME): $(OBJ)
	@echo "\e[48;2;0;155;0;1m Compile "$(NAME)" \e[0m\n"
	g++ $(OBJ) ${CFLAGS} -o $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

clean: hello
	@echo "\e[48;2;155;100;0;1m Clean "$(NAME)" dependencies \e[0m\n"
	$(RM) $(OBJ)
	@echo "\n\e[48;2;0;0;155;1m Done \e[0m\n"

fclean: hello clean
	@echo "\e[48;2;155;100;0;1m Uninstall "$(NAME)" \e[0m\n"
	$(RM) $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

%.o: %.c
	g++ ${CFLAGS} -c $< -o $@

re:	fclean all

.PHONY: all clean fclean re
