// C++ Program to Read a File Line by Line using ifstream 
#include <fstream> 
#include <iostream> 
#include <string> 

using namespace std; 

int main() 
{ 
	//Abrir arquivo
	ifstream inputFile("assembly.txt"); 

	string line; 

	// Ler linha por linha
	while (getline(inputFile, line)) { 
		cout << line << endl; 
	} 

	inputFile.close(); 
	return 0; 
}
