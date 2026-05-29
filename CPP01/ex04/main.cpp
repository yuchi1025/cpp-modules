/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:20:09 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:50:04 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
	if (argc != 4 || std::string(argv[2]).empty())
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
	else
	{
		std::ifstream in_file(argv[1]);

		if (!in_file)
		{
			std::cout << "Cannot open file" << std::endl;
			return 1;
		}

        std::string filename = std::string(argv[1]);
        std::string s1 = std::string(argv[2]);
        std::string s2 = std::string(argv[3]);
		std::string output_file = filename + ".replace";
		
		std::ofstream out_file(output_file.c_str());

		if (!out_file)
		{
			std::cout << "Cannot create output file" << std::endl;
			return 1;
		}

		std::string line;
		std::string new_line;
		size_t start_pos;
		size_t pos;

		while (std::getline(in_file, line))
		{
			start_pos = 0;
			if (s1 != s2)
			{
				while (line.find(argv[2], start_pos) != std::string::npos)
				{
					pos = line.find(argv[2], start_pos);
					new_line = line.substr(0, pos) + argv[3] + line.substr(pos + s1.length());
					line = new_line;
					start_pos = pos + s2.length();
				}
			}
			out_file << line;

            if (!in_file.eof())
                out_file << '\n';
		}

		in_file.close();
		out_file.close();
	}
	return 0;
}
