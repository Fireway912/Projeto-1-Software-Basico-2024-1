// C++ Program to Read a File Line by Line using ifstream 
#include <fstream> 
#include <iostream> 
#include <string> 

using namespace std; 

int main() 
{ 
	//Abrir arquivo
	ifstream inputFile("assembly.txt"); 
	string rotulo;
	string operador;
	string primeiro_operando;
	string segundo_operando;
	string line; 

	// Ler linha por linha
	while (getline(inputFile, line)) {
		//cout << line << endl;

		//se a linha tem dois pontos entao le rotulo sem dois pontos
		if(line.find(':')!=line.npos){
			//acha o rotulo e extrai
			rotulo.assign(line,0,line.find(':'));
			line.assign(line,line.find(':')+1,line.length()-line.find(':')-1);
			//acha o operador e extrai
			operador.assign(line, line.find_first_not_of(' '), line.find(' ',line.find_first_not_of(' '))-line.find_first_not_of(' '));
			line.assign(line,line.find(' ',line.find_first_not_of(' '))+1,line.length()-line.find(' ',line.find_first_not_of(' '))-1);
			//se operador nao eh STOP extrai o primeiro operando
			if(operador.find("STOP")==operador.npos){
				primeiro_operando.assign(line, line.find_first_not_of(' '), line.find(' ',line.find_first_not_of(' '))-line.find_first_not_of(' '));
				line.assign(line,line.find(' ',line.find_first_not_of(' '))+1,line.length()-line.find(' ',line.find_first_not_of(' '))-1);
				//se operador eh COPY extrai o segundo operando
				if(operador.find("COPY")!=operador.npos){
					segundo_operando.assign(line, line.find_first_not_of(' '), line.find(' ',line.find_first_not_of(' '))-line.find_first_not_of(' '));
					line.assign(line,line.find(' ',line.find_first_not_of(' '))+1,line.length()-line.find(' ',line.find_first_not_of(' '))-1);
				}
			}
			
			///Ver linha a linha o que cada token guarda
			cout << "Rotulo: |" << rotulo << "| Operador: |" << operador << "| 1st Operando: |" << primeiro_operando << "| 2nd Operando: |" << segundo_operando << "|EOL\n"; 
			rotulo = "";
			operador = "";
			primeiro_operando = "";
			segundo_operando = "";
		}
		else{
				//acha o operador e extrai
				operador.assign(line, line.find_first_not_of(' '), line.find(' ',line.find_first_not_of(' '))-line.find_first_not_of(' '));
				line.assign(line,line.find(' ',line.find_first_not_of(' '))+1,line.length()-line.find(' ',line.find_first_not_of(' '))-1);
				//se operador nao eh STOP extrai o primeiro operando
				if(operador.find("STOP")==operador.npos){
					primeiro_operando.assign(line, line.find_first_not_of(' '), line.find(' ',line.find_first_not_of(' '))-line.find_first_not_of(' '));
					line.assign(line,line.find(' ',line.find_first_not_of(' '))+1,line.length()-line.find(' ',line.find_first_not_of(' '))-1);
					//se operador eh COPY extrai o segundo operando
					if(operador.find("COPY")!=operador.npos){
						segundo_operando.assign(line, line.find_first_not_of(' '), line.find(' ',line.find_first_not_of(' '))-line.find_first_not_of(' '));
						line.assign(line,line.find(' ',line.find_first_not_of(' '))+1,line.length()-line.find(' ',line.find_first_not_of(' '))-1);
					}
				}

				///Ver linha a linha o que cada token guarda
			cout << "Rotulo: |" << rotulo << "| Operador: |" << operador << "| 1st Operando: |" << primeiro_operando << "| 2nd Operando: |" << segundo_operando << "|EOL\n"; 
			rotulo = "";
			operador = "";
			primeiro_operando = "";
			segundo_operando = "";

			}
		
	} 

	inputFile.close(); 
	return 0; 
}
