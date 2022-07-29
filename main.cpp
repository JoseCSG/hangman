#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>

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
void prepare_vector(std::vector <char>& incognita, std::string palabra)
{
    for (int i = 0; i < palabra.length(); i++)
    {
        incognita.push_back('_');
    }
    
}
int main(){
    srand(time(0));
    std::string Palabras[3]= {"autos","perros","animales"};
    std::vector <char> letras_usadas;
    std::vector <char> palabra_incognita;
    char letra;
    int random= rand()%3,errores=0;
    std::string palabra_adivinar = Palabras[random];
    prepare_vector(palabra_incognita,palabra_adivinar);




    std::cout<<"Write a letter"<<std::endl;
    std::cin>>letra;
    add_word(letras_usadas,letra);
    change_incognito(palabra_incognita,letras_usadas.back(),palabra_adivinar);
    show_incognito(palabra_incognita);
    std::cout<<"Write a letter"<<std::endl;
    std::cin>>letra;
    add_word(letras_usadas,letra);
    change_incognito(palabra_incognita,letras_usadas.back(),palabra_adivinar);
    show_incognito(palabra_incognita);
    show_letras_usadas(letras_usadas);
    
    
    
    
    
    return 0;
}