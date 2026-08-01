# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/30 13:49:25 by yucchen           #+#    #+#              #
#    Updated: 2026/07/22 11:27:11 by yucchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and parameters
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# File name
NAME = forms

# Mandatory Sources
SOURCES = Bureaucrat.cpp			 \
		  AForm.cpp					 \
		  ShrubberyCreationForm.cpp	 \
		  RobotomyRequestForm.cpp	 \
		  PresidentialPardonForm.cpp \
		  main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Bureaucrat.hpp			 \
		  AForm.hpp					 \
		  ShrubberyCreationForm.hpp  \
		  RobotomyRequestForm.hpp	 \
		  PresidentialPardonForm.hpp

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
