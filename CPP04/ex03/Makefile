# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/30 13:49:25 by yucchen           #+#    #+#              #
#    Updated: 2026/06/30 16:28:21 by yucchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and parameters
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# File name
NAME = interface

# Mandatory Sources
SOURCES = AMateria.cpp		\
		  Character.cpp		\
		  Cure.cpp			\
		  Ice.cpp			\
		  MateriaSource.cpp \
		  main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = AMateria.hpp		 \
		  Character.hpp		 \
		  Cure.hpp			 \
		  Ice.hpp			 \
		  MateriaSource.hpp  \
		  ICharacter.hpp	 \
		  IMateriaSource.hpp

# Rules
# Compile
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

# Compile each .cpp into .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean: 
	rm -f $(OBJECTS) 

# Full clean / Clean object files and executable
fclean: clean
	rm -f $(NAME)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re 
