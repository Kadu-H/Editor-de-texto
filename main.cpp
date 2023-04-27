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

int main(){

    std::string nameFile = "";
    std::string conteudo = "";

    CreateFile(nameFile,conteudo);

    return 0;
}