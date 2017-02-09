#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgogol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/21 18:10:57 by tgogol            #+#    #+#              #
#    Updated: 2017/01/21 18:11:17 by tgogol           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =		fillit
FLAGS =		-Wall -Wextra -Werror
OBJECTS = 	main.o			\
			figure.o		\
			check_fig.o		\
			other_func.o	\

all : $(NAME)

$(NAME) : $(OBJECTS)
	gcc $(FLAGS) $(OBJECTS) -o $(NAME)

%.o : %.c
	gcc $(FLAGS) -o $@ -c $< -I ./$(NAME).h

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
