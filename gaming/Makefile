# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oseng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/18 11:49:03 by oseng             #+#    #+#              #
#    Updated: 2016/01/18 11:49:14 by oseng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GC = clang++

# FLAG = -Wall -Wextra -Werror -lncurses
FLAG = -Wall -Wextra -Werror
# FLAG = -lncurses
CUR = -lncurses

# SRCS = main.cpp
# SRCS = main.cpp ACharacter.cpp Drone.cpp GameObject.cpp Player.cpp Structs.cpp
SRCS = main.cpp GameWorld.cpp Laser.cpp ACharacter.cpp Drone.cpp GameObject.cpp Player.cpp Structs.cpp


NAME = ft_retro

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@echo "by 👽    ft_retro 🚀"

		@echo "\033[92mCompiling"
		@$(GC) $(FLAGS) -o $(NAME) $(OBJ) $(CUR)
		@echo "\033[96m->Done"

%.o: %.cpp
	 @$(GC)  $(FLAGS) -c $<

clean:
		@echo "\033[92mDeleting"
		@rm -f $(OBJ)
		@echo "\033[96mClean done"


fclean: clean
		@echo "\033[92mDeleting"
		@rm -f $(NAME)
		@echo "\033[96mFclean Done"

re: fclean all

.PHONY: all clean fclean re
