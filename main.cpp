#include <iostream>
#include <vector>

void add_word(std::vector <char>& letras,char letra)
{
    letras.push_back(letra);
}
void change_incognito(std::vector <char>& incognita,char letra, std::string palabra)
{
    for (int i = 0; i < incognita.size(); i++)
    {
        if (palabra[i]==letra)
        {
            incognita[i]=letra;
        }
    }
}
void show_incognito(std::vector <char>& incognita)
{
    for (int i = 0; i < incognita.size(); i++)
    {
        std::cout<<incognita[i]<<" ";
    }
    std::cout<<"\n";
}
void show_letras_usadas(std::vector <char>& letras_usadas)
{
    for (int i = 0; i < letras_usadas.size(); i++)
    {
        std::cout<<letras_usadas[i]<<" ";
    }
    std::cout<<"\n";
}
int main(){

    std::string Palabras[3]= {"autos","perros","animales"};
    std::vector <char> letras_usadas;
    std::vector <char> palabra_incognita;
    
    for (auto &&i : Palabras[0])
    {
        std::cout<<i<<" ";
    }    
    int i=0;
    for (int i = 0; i < Palabras[0].length(); i++)
    {
        palabra_incognita.push_back('_');
    }
    
    
    char letra;

    
    /*for (int i = 0; i < Palabras[0].length(); i++)
    {
        if (Palabras[0][i]==letras_usadas.back())
        {
            std::cout<<Palabras[0][i]<<" ";
        }
        else
        {
            std::cout<<"_ ";
            
        }   
    }*/
    /*show_incognito(palabra_incognita);*/
    std::cout<<"Write a letter"<<std::endl;
    std::cin>>letra;
    add_word(letras_usadas,letra);
    change_incognito(palabra_incognita,letras_usadas.back(),Palabras[0]);
    show_incognito(palabra_incognita);
    std::cout<<"Write a letter"<<std::endl;
    std::cin>>letra;
    add_word(letras_usadas,letra);
    change_incognito(palabra_incognita,letras_usadas.back(),Palabras[0]);
    show_incognito(palabra_incognita);
    show_letras_usadas(letras_usadas);
    
    
    
    
    
    return 0;
}