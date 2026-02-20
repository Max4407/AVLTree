#include <iostream>
#include <sstream>
#include "avl.h"

using namespace std;

int main(){
	AVL tree; 

	std::regex open = std::regex("^[\"]");
	std::regex close = std::regex("[\"]$");
	
	std::string line;
	std::getline(std::cin,line);

	int commands = std::stoi(line);
	for (int i = 0; i < commands; i++) {
		std::string command;
		std::getline(std::cin,line);
		stringstream in(line);
		in >> command;
		if (command == "insert") {
			std::string name = "", id;
			bool opened = true;
			while (opened) {
				std::string temp;
				in >> temp;
				name += temp;
				if (std::regex_search(temp,close))
					opened = false;
				else 
					name += " ";
			}
			name = name.substr(1,name.size() - 2);
			
			in >> id;
			std::cout << (tree.insert(name,id) ? "successful" : "unsuccessful") << std::endl;
		}
		else if (command == "remove") {
			std::string id;
			in >> id;
			std::cout << (tree.remove(id) ? "successful" : "unsuccessful") << std::endl;
		}
		else if (command == "search") {
			std::string arg;

			in >> arg;

			std::regex name = std::regex("^[A-Za-z ]*$");
    		std::regex id = std::regex("^[0-9]*$");
			if (std::regex_search(arg,name)) {
				std::vector<std::string> ids = tree.searchByName(arg);
				if (ids.size() == 0) 
					std::cout << "unsuccessful" << std::endl;
				else {
					for (std::string s : ids)
						std::cout << s << std::endl;
				}
			}
			if (std::regex_search(arg,id)) {
				std::cout << tree.searchByID(arg) << std::endl;
			}
		}
		else if (command == "printInorder") {
			std::vector<std::string> names = tree.inOrderNames();
			for (size_t i = 0; i < names.size() - 1; i++)
				std::cout << names[i] << ", ";
			std::cout << names[names.size()-1] << std::endl;
		}
		else if (command == "printPreorder") {
			std::vector<std::string> names = tree.preOrderNames();
			for (size_t i = 0; i < names.size() - 1; i++)
				std::cout << names[i] << ", ";
			std::cout << names[names.size()-1] << std::endl;
		}
		else if (command == "printPostorder") {
			std::vector<std::string> names = tree.postOrderNames();
			for (size_t i = 0; i < names.size() - 1; i++)
				std::cout << names[i] << ", ";
			std::cout << names[names.size()-1] << std::endl;
		}
		else if (command == "printLevelCount"){
			std::cout << tree.levelCount();
		}			
		else if (command == "removeInorder") {
			std::string n;
			in >> n;
			std::cout << (tree.removeInorder(std::stoi(n)) ? "successful" : "unsuccessful") << std::endl;
		}
	}
	return 0;
}
