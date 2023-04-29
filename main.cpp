#include <iostream>
#include <fstream>
#include <sstream>


//Cria um arquivo caso não haja e envia o valor da variavel conteudo para dentro dele, se tudo deu certo o valor de retorno é 1, se não 0.
int CreateFile(std::string nameFile, std::string conteudo){

    std::ofstream arquivo;
    arquivo.open(nameFile,std::ios::out);

    if(arquivo.is_open()){
        arquivo << conteudo;
        arquivo.close();
        return 1;
    }
    else{
        return 0;
    }
}

//Abre o arquivo e copia o conteudo, se tudo deu certo o valor de retorno é 1, se não 0.
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
        return 1;
        
    }
    else{
        return 0;
    }

}

int main(){

    //Variaveis basicas para funcionamento do codigo.
    std::string nameFile = "";
    std::string conteudo = "";

    //Verifica se o arquivo foi Salvo.
    if(CreateFile(nameFile,conteudo) == 1){
        std::cout<< "Arquivo Salvo!";
    }
    else{
        std::cout<< "Erro ao salvar arquivo.";
    }

    //Verifica se o Arquivo foi lido e copiado;
    if(ReadFile(nameFile) == 1){
        std::cout<< "Arquivo Copiado!";
    }
    else{
        std::cout<< "Erro ao ler arquivo.";
    }

    return 0;
}