# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 15:34:02 by raveriss          #+#    #+#              #
#    Updated: 2024/03/13 15:34:06 by raveriss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


INCLUDES = Account.hpp

SRC = tests.cpp Account.cpp

NAME = Account

OBJ = $(SRC:.cpp=.o)

FLAGS = -std=c++98 -MMD

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
