# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/01 17:04:27 by yucchen           #+#    #+#              #
#    Updated: 2026/06/25 16:11:28 by yucchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and parameters
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# File name
NAME = diamondtrap

# Mandatory Sources
SOURCES = ClapTrap.cpp	  \
		  ScavTrap.cpp	  \
		  FragTrap.cpp	  \
		  DiamondTrap.cpp \
		  main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = ClapTrap.hpp	  \
		  ScavTrap.hpp	  \
		  FragTrap.hpp	  \
		  DiamondTrap.hpp

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
