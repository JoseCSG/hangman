#include <iostream>
#include <vector>

void add_word(std::vector <char>& letras,char letra)
{
    letras.push_back(letra);
}

int main(){

    std::string Palabras[3]= {"autos","perros","animales"};
    std::vector <char> letras_usadas;
    letras_usadas.push_back('a');
    for (auto &&i : Palabras[0])
    {
        std::cout<<i<<" ";
    }
    std::cout<<Palabras[0].length()<<"\n";
    
    for (int i = 0; i < Palabras[0].length(); i++)
    {
        std::cout<<"_ ";
    }

    for (auto &&i : Palabras[0])
    {
        for (int g = 0; g < 28; g++)
        {
            if (i==letras_usadas[g])
            {
                std::cout<<"ojala funciones";
            }
            
        }  
        
    }
    char letra;
    for (int i = 0; i < 10; i++)
    {
        std::cin>>letra;
        add_word(letras_usadas,letra);
    }
    for (auto &&i : letras_usadas)
    {
        std::cout<<i<<" ";
    }
    
    
    
    
    return 0;
}