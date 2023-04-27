#include <iostream>
#include <fstream>
#include <sstream>


int CreateFile(std::string nameFile, std::string conteudo){

    std::ofstream arquivo;
    arquivo.open(nameFile,std::ios::out);

    if(arquivo.is_open()){
        arquivo << conteudo;
        arquivo.close();
    }

    return 0;
}

int ReadFile(std::string nameFile){

    std::ifstream arquivo;
    std::string conteudo;

    std::stringstream strStream;

    arquivo.open(nameFile,std::ios::in);

    if (arquivo.is_open()){

        strStream << arquivo.rdbuf();
        conteudo = strStream.str();

        arquivo.close();

        std::cout << conteudo;
        
    }
    
    return 0;
}

int main(){

    std::string nameFile = "";
    std::string conteudo = "";

    CreateFile(nameFile,conteudo);
    ReadFile(nameFile);

    return 0;
}