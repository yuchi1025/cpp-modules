# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/14 10:24:30 by yucchen           #+#    #+#              #
#    Updated: 2026/08/20 17:49:53 by yucchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and parameters
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# File name
NAME = whatever

# Mandatory Sources
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = whatever.hpp 

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
