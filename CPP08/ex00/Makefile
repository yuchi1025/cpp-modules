# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yucchen <yucchen@student.42singapore.sg>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/27 15:44:59 by yucchen           #+#    #+#              #
#    Updated: 2026/08/27 16:42:15 by yucchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and parameters
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# File name
NAME = easyfind

# Mandatory Sources
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = easyfind.hpp 

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
