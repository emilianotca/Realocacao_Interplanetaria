#include <iostream>
#include <fstream>
#include <string>

#include "../include/Control_Center.h"

int main(int argc, char* argv[])
{
    // Opening file
    std::ifstream input_file ("in2.txt");
    
    std::string current_line;
    std::string parsing_aux;
    std::string command_aux_1; // Argument of type string
    int command_aux_2 {0}; // Argument of type int 
    int command_aux_3 {0}; // Argument of type int
    int number_of_servers {0};

    if(input_file.is_open()) // Sanity check for input file - file exists
    {
	getline(input_file, current_line);
	number_of_servers = std::stoi(current_line);

	Control_Center main_control(number_of_servers);

	while(getline(input_file, current_line))
	{
		// Reading each line and identifying the corresponding command
		parsing_aux = current_line.at(0);

		if(parsing_aux == "I") // INFO
		{
			// Getting command arguments
			// Addressee server
			command_aux_1 = current_line.substr(current_line.find_first_of(' '), current_line.find_first_of('\"')-current_line.find_first_of(' '));
			command_aux_2 = std::stoi(command_aux_1);

			// Data
			command_aux_1 = current_line.substr(current_line.find_first_of('\"'), current_line.size());
			command_aux_1 = command_aux_1.substr(1, command_aux_1.size()-2); // Filtering out quotes
			// Calling INFO
			main_control.INFO(command_aux_2, command_aux_1);

		}
		else if(parsing_aux == "W") // WARN
		{
			// Getting command arguments
			// Addressee server
			command_aux_1 = current_line.at(5);
			command_aux_2 = std::stoi(command_aux_1);

			// Position of data in danger
			command_aux_1 = current_line.at(7);
			command_aux_3 = std::stoi(command_aux_1);

			// Calling WARN
			main_control.WARN(command_aux_2, command_aux_3);			
		}
		else if(parsing_aux == "T") // TRAN
		{
			// Getting command arguments
			// Addressee servers
			command_aux_1 = current_line.at(5);
			command_aux_2 = std::stoi(command_aux_1);

			command_aux_1 = current_line.at(7);
			command_aux_3 = std::stoi(command_aux_1);

			// Calling TRAN
			main_control.TRAN(command_aux_2, command_aux_3);

		}
		else if(parsing_aux == "E") // ERRO
		{
			// Getting command arguments
			command_aux_1 = current_line.at(5);
			command_aux_2 = std::stoi(command_aux_1);

			// Calling ERRO
			main_control.ERRO(command_aux_2);
		}
		else if(parsing_aux == "S") // SEND
		{
			// Calling SEND
			main_control.SEND();
		}
		else // FLUSH
		{
			main_control.FLUSH();
		}
	}

    }
    else // File does not exist
    {
        return 1;
    }
    return 0;
}
