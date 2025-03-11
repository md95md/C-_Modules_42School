NAME        =   phonebook

SRCS        =   main.cpp utils.cpp contact.cpp

HEADER      =   phonebook.hpp

OBJ_DIR     =   build

OBJS        =   $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

INCLUDES    =   -I.

CFLAGS      =   -Wall -Wextra -Werror -std=c++98 -g -O0

CC          =   g++

RM          =   rm -rf

CONTACTS_TXT = contacts.txt

CYAN        =   \033[1;36m
MAGENTA     =   \033[1;35m
GREEN       =   \033[1;32m
END         =   \033[0m

.PHONY      :   all clean fclean re

all         :   $(NAME)
	@echo -e "$(GREEN)\nCompilation successful! You can now run ./phonebook.exe\n$(END)"

$(NAME)     :   $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o : %.cpp $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean       :   
	@$(RM) $(OBJS) $(CONTACTS_TXT)
	@echo -e "\n'clean' status: DONE\n"
				
fclean      : clean
	@$(RM) $(NAME) $(OBJ_DIR)
	@echo -e "$(GREEN)\n'fclean' status: DONE\n$(END)"

re          : fclean all
	@echo -e "\n're' status: DONE\n"
