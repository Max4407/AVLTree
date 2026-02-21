#include <catch2/catch_test_macros.hpp>
//#include <iostream>
#include <random>
#include "avl.h"

//	Maxwell FitzGerald  UFID:16166090

using namespace std;

TEST_CASE("insertion and rotation work properly", "[insertion/rotation]"){
	SECTION("insertion works properly", "[insertion/rotation]"){
		AVL tester;
		tester.insert("Max", "20000000");
		tester.insert("Kevin","30000000");
		tester.insert("Raul","10000000");

		vector<std::string> testNames = tester.preOrderNames();

		REQUIRE(testNames.size() == 3); 
		REQUIRE(testNames[0] == "Max"); 
		REQUIRE(testNames[1] == "Raul"); 
		REQUIRE(testNames[2] == "Kevin"); 

		SECTION("height greater than two") {
			tester.insert("Ryan","05000000");
			tester.insert("Emma","40000000");
			vector<std::string> testNames1 = tester.preOrderNames();
			REQUIRE(testNames1.size() == 5); 
			REQUIRE(testNames1[0] == "Max"); 
			REQUIRE(testNames1[1] == "Raul");
			REQUIRE(testNames1[2] == "Ryan"); 
			REQUIRE(testNames1[3] == "Kevin"); 
			REQUIRE(testNames1[4] == "Emma");
		}
	}

	SECTION("insertion automatically rotates LL", "[insertion/rotation]"){
		AVL tester;
		tester.insert("Max", "20000000");
		tester.insert("Kevin","30000000");
		tester.insert("Raul","40000000");

		vector<std::string> testNames = tester.preOrderNames();

		REQUIRE(testNames.size() == 3); 
		REQUIRE(testNames[0] == "Kevin"); 
		REQUIRE(testNames[1] == "Max");
		REQUIRE(testNames[2] == "Raul"); 
	}

	SECTION("LL rotation for child node", "[insertion/rotation]") {
		AVL tester;
		tester.insert("Max", "50000000");
		tester.insert("Kevin","30000000");
		tester.insert("Raul","70000000");
		tester.insert("Ryan","60000000");
		tester.insert("Evan","20000000");
		tester.insert("Omar","80000000");
		tester.insert("Tomas","10000000");

		vector<std::string> testNames = tester.preOrderNames();

		REQUIRE(testNames.size() == 7); 
		REQUIRE(testNames[0] == "Max"); 
		REQUIRE(testNames[1] == "Evan");
		REQUIRE(testNames[2] == "Tomas"); 
		REQUIRE(testNames[3] == "Kevin"); 
		REQUIRE(testNames[4] == "Raul");
		REQUIRE(testNames[5] == "Ryan"); 
		REQUIRE(testNames[6] == "Omar"); 
	}

	SECTION("insertion automatically rotates RR", "[insertion/rotation]"){
		AVL tester;
		tester.insert("Max", "20000000");
		tester.insert("Kevin","15000000");
		tester.insert("Raul","10000000");


		vector<std::string> testNames = tester.preOrderNames();

		REQUIRE(testNames.size() == 3); 
		REQUIRE(testNames[0] == "Kevin"); 
		REQUIRE(testNames[1] == "Raul");
		REQUIRE(testNames[2] == "Max"); 
	}

	SECTION("RR rotation for child node", "[insertion/rotation]") {
		AVL tester;
		tester.insert("Max", "50000000");
		tester.insert("Kevin","20000000");
		tester.insert("Raul","70000000");
		tester.insert("Ryan","30000000");
		tester.insert("Evan","80000000");
		tester.insert("Omar","10000000");
		tester.insert("Tomas","90000000");

		vector<std::string> testNames = tester.preOrderNames();

		REQUIRE(testNames.size() == 7); 
		REQUIRE(testNames[0] == "Max"); 
		REQUIRE(testNames[1] == "Kevin");
		REQUIRE(testNames[2] == "Omar"); 
		REQUIRE(testNames[3] == "Ryan"); 
		REQUIRE(testNames[4] == "Evan");
		REQUIRE(testNames[5] == "Raul"); 
		REQUIRE(testNames[6] == "Tomas"); 
	}

	SECTION("insertion automatically rotates LR", "[insertion/rotation]"){
		AVL tester;
		tester.insert("Max","20000000");
		tester.insert("Kevin","10000000");
		tester.insert("Raul","15000000");

		vector<std::string> testNames = tester.preOrderNames();

		REQUIRE(testNames.size() == 3); 
		REQUIRE(testNames[0] == "Raul"); 
		REQUIRE(testNames[1] == "Kevin");
		REQUIRE(testNames[2] == "Max"); 
	}

	SECTION("LR rotation for child node", "[insertion/rotation]") {
		AVL tester;
		tester.insert("Max", "50000000");
		tester.insert("Kevin","30000000");
		tester.insert("Raul","70000000");
		tester.insert("Ryan","60000000");
		tester.insert("Evan","20000000");
		tester.insert("Omar","80000000");
		tester.insert("Tomas","25000000");

		vector<std::string> testNames = tester.preOrderNames();

		REQUIRE(testNames.size() == 7); 
		REQUIRE(testNames[0] == "Max"); 
		REQUIRE(testNames[1] == "Tomas");
		REQUIRE(testNames[2] == "Evan"); 
		REQUIRE(testNames[3] == "Kevin"); 
		REQUIRE(testNames[4] == "Raul");
		REQUIRE(testNames[5] == "Ryan"); 
		REQUIRE(testNames[6] == "Omar"); 
	}


	SECTION("insertion automatically rotates RL", "[insertion/rotation]"){
		AVL tester;
		tester.insert("Max","20000000");
		tester.insert("Kevin","30000000");
		tester.insert("Raul","25000000");

		vector<std::string> testNames = tester.preOrderNames();

		REQUIRE(testNames.size() == 3); 
		REQUIRE(testNames[0] == "Raul"); 
		REQUIRE(testNames[1] == "Max");
		REQUIRE(testNames[2] == "Kevin"); 
	}

	SECTION("RL rotation for child node", "[insertion/rotation]") {
		AVL tester;
		tester.insert("Max", "50000000");
		tester.insert("Kevin","20000000");
		tester.insert("Raul","70000000");
		tester.insert("Ryan","30000000");
		tester.insert("Evan","80000000");
		tester.insert("Omar","10000000");
		tester.insert("Tomas","75000000");

		vector<std::string> testNames = tester.preOrderNames();

		REQUIRE(testNames.size() == 7); 
		REQUIRE(testNames[0] == "Max"); 
		REQUIRE(testNames[1] == "Kevin");
		REQUIRE(testNames[2] == "Omar"); 
		REQUIRE(testNames[3] == "Ryan"); 
		REQUIRE(testNames[4] == "Tomas");
		REQUIRE(testNames[5] == "Raul"); 
		REQUIRE(testNames[6] == "Evan"); 
	}

}

TEST_CASE("parses input for invalid names/IDs", "[parsing input]") {
	AVL tester;

	SECTION("numbers in name") {
		REQUIRE(!tester.insert("Ma123", "20000000"));
	}		

	SECTION("special characters in name") {
		REQUIRE(!tester.insert("Max$", "20000000"));
	}		

	SECTION("letters in ID") {
		REQUIRE(!tester.insert("Max", "21b00000"));
	}		

	SECTION("ID not long enough") {
		REQUIRE(!tester.insert("Max", "210"));
	}		

	SECTION("ID already present") {
		tester.insert("Max", "20000000");
		REQUIRE(!tester.insert("Max", "20000000"));
	}		
}

TEST_CASE("100 inputs, remove 10","[insertion/removal]",) {
	AVL tester;

	for (int i = 1; i <= 100; i++) {
		tester.insert("Max",std::to_string(10000000 + i));
	}

	while (tester.size > 90) {
		srand(time(0));
		int random = 10000000 + (rand() % 100) + 1;
		tester.remove(std::to_string(random));
	}

	vector<std::string> result = tester.inOrderIDs();
	for (int i = 1; i < 90; i++) {
		REQUIRE(std::stoi(result[i]) > std::stoi(result[i-1]));
	}
	
}

TEST_CASE("edge cases","[edge cases]") {
	AVL tester;

	SECTION("removing root") {
		tester.insert("Max Fitz","10000000");
		tester.insert("Max FitzGerald","20000000");
		REQUIRE(tester.remove("10000000"));

		vector<std::string> testNames = tester.preOrderNames();

		REQUIRE(testNames.size() == 1); 
		REQUIRE(testNames[0] == "Max FitzGerald"); 
	}

	SECTION("removing nonexistent node") {
		tester.insert("Max Fitz","10000000");
		tester.insert("Max FitzGerald","20000000");
		REQUIRE(!tester.remove("00000000"));

		vector<std::string> testNames = tester.preOrderNames();

		REQUIRE(testNames.size() == 2); 
		REQUIRE(testNames[0] == "Max Fitz"); 
		REQUIRE(testNames[1] == "Max FitzGerald"); 
	}

	SECTION("search empty tree") {
		REQUIRE(tester.searchByID("00000000") == "unsuccessful");
	}
}

TEST_CASE("testing all three deletion cases","[removal]") {
	AVL tester;

	SECTION("no children") {
		tester.insert("Max Fitz","10000000");
		tester.insert("Max FitzGerald","20000000");
		REQUIRE(tester.remove("20000000"));

		vector<std::string> testNames = tester.preOrderNames();

		REQUIRE(testNames.size() == 1); 
		REQUIRE(testNames[0] == "Max Fitz"); 
	}

	SECTION("one child") {
		tester.insert("Max Fitz","20000000");
		tester.insert("Max FitzGerald","10000000");
		tester.insert("Kevin", "30000000");
		tester.insert("Raul","05000000");
		REQUIRE(tester.remove("10000000"));

		vector<std::string> testNames = tester.preOrderNames();

		REQUIRE(testNames.size() == 3); 
		REQUIRE(testNames[0] == "Max Fitz"); 
		REQUIRE(testNames[1] == "Raul");
		REQUIRE(testNames[2] == "Kevin");
	}

	SECTION("two children") {
		tester.insert("Max Fitz","20000000");
		tester.insert("Max FitzGerald","10000000");
		tester.insert("Kevin", "30000000");
		tester.insert("Raul","05000000");
		tester.insert("Ryan","15000000");
		REQUIRE(tester.remove("10000000"));

		vector<std::string> testNames = tester.preOrderNames();

		REQUIRE(testNames.size() == 4); 
		REQUIRE(testNames[0] == "Max Fitz"); 
		REQUIRE(testNames[1] == "Ryan");
		REQUIRE(testNames[2] == "Raul");
		REQUIRE(testNames[3] == "Kevin");
	}
}