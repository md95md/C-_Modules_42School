NAME		=	phonebook

SRCS		=	main.cpp utils.cpp

HEADER		=	phonebook.hpp

OBJ_DIR		=	build

OBJS		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

INCLUDES	=	-I.

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g -O0

CC			=	g++

RM			=	rm -rf

YELLOW		=	"\033[1;33m"
GREEN		=	"\033[1;32m"
END			=	"\033[0m"

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

# Компиляция .o файлов в папку build/
$(OBJ_DIR)/%.o : %.cpp $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Создание папки для объектных файлов
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean		:	
	@$(RM) $(OBJS)
	@echo $(YELLOW) "\n'clean' status: DONE\n" $(END)
				
fclean		: clean
	@$(RM) $(NAME) $(OBJ_DIR)
	@echo $(YELLOW) "\n'fclean' status: DONE\n" $(END)

re			: fclean all
	@echo $(GREEN) "\n're' status: DONE\n" $(END)
