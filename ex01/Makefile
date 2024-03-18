# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 10:38:25 by bvaujour          #+#    #+#              #
#    Updated: 2024/03/18 16:56:47 by raveriss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


INCLUDES = Contact.hpp PhoneBook.hpp

SRC = Contact.cpp PhoneBook.cpp main.cpp

NAME = phonebook

OBJ = $(SRC:.cpp=.o)

FLAGS = -std=c++98 -g -Wall -Werror -Wextra -MMD

CC = c++

DEP	=	$(OBJ:.o=.d)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all		: $(NAME)

$(NAME)	:  $(OBJ) Makefile
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean	:
	rm -rf $(OBJ)
	rm -rf $(DEP)
fclean	: clean
	rm -rf $(NAME)

re	: fclean all

-include $(DEP)

.PHONY: all clean fclean re
